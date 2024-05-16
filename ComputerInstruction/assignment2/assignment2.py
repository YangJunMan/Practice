import sys

str_function=''
sb_function=''
sb_loop=0
num_count=0
array_register=[0 for i in range(200) ]
pc=0
DATA_MEMORY=[0xFFFFFFFF for i in range(16384) ]

# change 2's complement to decimal
def twos_comp(value, bits):
    if (value & (1 << (bits - 1))) != 0:
        value = value - (1 << bits)   
    return value                    

    
count=0
def U_Format():
    global pc
    #print('U_Format')
    str_function=''
    if(opcode_Binary=='0110111'):
        #print('LUI')
        str_function='lui'
        imm = full_Binary[0:20]
        rd = full_Binary[20:25]
        
        imm_value=int(imm,2)
        
#        print(imm_value)
#        print(format(imm_value,'b'))   
        
        sign_extend_imm=imm_value
             
        if (imm[0]=='1'):
#            sign_extend_imm=sign_extend_imm|0xfff00000
#            sign_extend_imm=~sign_extend_imm
#            sign_extend_imm=sign_extend_imm+1
#            sign_extend_imm=-sign_extend_imm
            
#            print(format(sign_extend_imm,'b'))
            
            int_decimm = twos_comp(sign_extend_imm, 20)
            
        else:
            int_decimm=int(imm,2)      
            #shoud be 2^12.  
        
        int_decimm=int_decimm<<12
        imm_value=sign_extend_imm<<12

        #register에 저장
        str_decimm=str(hex(int_decimm))
        dec_Rd=int(rd,2)
        str_Rd='x'+str(dec_Rd)
        
        array_register[dec_Rd]=imm_value
        
        pc+=1
        
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_decimm
    
    elif(opcode_Binary=='0010111'):
        #print('AUIPC')
        str_function='auipc'
        imm = full_Binary[0:20]
        rd = full_Binary[20:25]
        
        
        imm_value=int(imm,2)
        
        
        sign_extend_imm=imm_value
             
        if (imm[0]=='1'):
#            sign_extend_imm=sign_extend_imm|0xfff00000
#            sign_extend_imm=~sign_extend_imm                        
#            sign_extend_imm=sign_extend_imm+1
#            sign_extend_imm=-sign_extend_imm
            
            int_decimm = twos_comp(sign_extend_imm, 20)
        else:
            int_decimm=int(imm,2)     
               
        int_decimm=int_decimm<<12
        imm_value=sign_extend_imm<<12
        
        str_decimm=str(int_decimm)
        int_rd=int(rd,2)
        str_Rd='x'+str(int_rd)
        
        array_register[int_rd] = (pc * 4) + imm_value
        
        pc+=1
         
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_decimm
        
    return 'ERROR: U_Format'

def UJ_Format():
    global pc
    global num_count
    #print('UJ_Format')
    str_function=''
    if(opcode_Binary=='1101111'):
        #print('JAL')
        str_function='jal'
        imm=full_Binary[0:20]
#last : '0'. it should be 2^..
        str_sumimm=imm[0]+imm[12:20]+imm[11]+imm[1:11]+'0'
        
        
        if (str_sumimm[0]=='1'):
            int_decimm = twos_comp(int(str_sumimm,2), len(str_sumimm))
        else:
            int_decimm=int(str_sumimm,2)  

        str_decimm=str(int_decimm) 
        
        rd=full_Binary[20:25]
        
        int_rd=int(rd,2)

        array_register[int_rd] = (pc * 4) + 4
        pc += int(int_decimm / 4)

        str_Rd='x'+str(int_rd)
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_decimm
    return 'Error: J_Format'
    
def I_Format():
    global pc
    global num_count
    #print('I_Format')
    str_function=''
    if(opcode_Binary=='1100111'):
        #print('JALR')
        str_function='jalr'
        offset=full_Binary[0:12]
        rs1=full_Binary[12:17]
        rd = full_Binary[20:25]
        int_rs1=int(rs1,2)
        int_rd=int(rd,2)
        int_offset=int(offset,2)
        str_Rd='x'+str(int_rd)
        
        if (offset[0]=='1'):
            str_offset = twos_comp(int_offset, len(offset))
        else:
            str_offset=str(int_offset)
            
        array_register[int_rd] = int(pc * 4) + 4
        pc += int((array_register[int_rs1]+int_offset) / 4)
        
        str_Rs1='x'+str(int(rs1,2))
        
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_offset+'('+str_Rs1+')'
    elif(opcode_Binary=='0000011'):
        #print('LB, LH, LW, LBU, LHU')
        str_function=''
        
        imm=full_Binary[0:12]
        res1=full_Binary[12:17] 
        funct3=full_Binary[17:20]  
        rd=full_Binary[20:25]   
        
        imm_value=int(imm,2)
        
        sign_extend_imm=imm_value
             
        if (imm[0]=='1'):
            sign_extend_imm=sign_extend_imm|0xfffff000
            sign_extend_imm=~sign_extend_imm
            sign_extend_imm=sign_extend_imm+1
            sign_extend_imm=-sign_extend_imm
            int_decimm = twos_comp(sign_extend_imm, 32)
            
        else:
            int_decimm=int(imm,2)
        
        str_decimm=str(int_decimm)  
        int_res1=int(res1,2)
        hex_res1=hex(int_res1)
        int_rd=int(rd,2)
        hex_rd=hex(int_rd)
        hex_decimm=hex(int_decimm)
        str_res1='x'+str(int_res1)
        str_Rd='x'+str(int_rd)

        int_base_address=array_register[int_res1]
        
        if (int_base_address>=0x80000000):
            int_base_address=twos_comp(int_base_address, 32)

#        if(funct3=='000'):
#            str_function='lb'
#        elif(funct3=='001'):
#            str_function='lh'
        if(funct3=='010'):
            str_function='lw'
            array_register[int_rd]=DATA_MEMORY[int(((int_base_address+int_decimm)-0x10000000)/4)]
            
#        elif(funct3=='100'):
#            str_function='lbu'
#        elif(funct3=='101'):
#            str_function='lhu'
        else:
            str_function='NoFunct'
        pc+=1
        
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_decimm + '(' + str_res1+ ')'
    elif(opcode_Binary=='0010011'):
        #print('ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI')
        imm=full_Binary[0:12]
        res1=full_Binary[12:17]
        funct3=full_Binary[17:20]
        rd=full_Binary[20:25]
        
        imm_value=int(imm,2)

        sign_extend_imm=imm_value
             
        if (imm[0]=='1'):
            sign_extend_imm=sign_extend_imm|0xfffff000
            sign_extend_imm=~sign_extend_imm
            
            
            sign_extend_imm=sign_extend_imm+1
            sign_extend_imm=-sign_extend_imm
            
            int_decimm = twos_comp(sign_extend_imm, 32)
        else:
            int_decimm=int(imm,2)
        
        str_decimm=str(int_decimm)
        int_res1=int(res1,2)
        hex_res1=hex(int_res1)
        int_rd=int(rd,2)
        str_res1='x'+str(int_res1)
        str_Rd='x'+str(int_rd)

        if(funct3=='000'):
            str_function='addi'
            if(array_register[int_res1]+int_decimm>=0):
                array_register[int_rd]=array_register[int_res1]+int_decimm
            else:
                array_register[int_rd]=array_register[int_res1]+0xFFFFFFFF+int_decimm +1 
        elif(funct3=='010'):
            str_function='slti'
            if (twos_comp(array_register[int_res1],32)<int_decimm):
                array_register[int_rd]=1
            else:
                array_register[int_rd]=0
            
        elif(funct3=='011'):
            str_function='sltiu'
        elif(funct3=='100'):
            str_function='xori'
            array_register[int_rd]=array_register[int_res1]^sign_extend_imm
        elif(funct3=='110'):
            str_function='ori'
            array_register[int_rd]=array_register[int_res1]|sign_extend_imm
        elif(funct3=='111'):
            str_function='andi'           
            array_register[int_rd]=array_register[int_res1]&sign_extend_imm
        
        #Shift immediate 명령어
        elif(funct3=='101' or funct3=='001'):
            int_shampt=int(imm[7:12],2)
            str_Shamt=str(int_shampt) 
            if int_shampt<0:
                int_shampt=0
            if(funct3=='001'):
                str_function='slli'
                array_register[int_rd]=array_register[int_res1]<<int_shampt
            elif(imm[0:6]=='000000'):
                str_function='srli'
                array_register[int_rd]=array_register[int_res1]>>int_shampt
                
            elif(imm[0:6]=='010000'):
                str_function='srai'
                if(array_register[int_res1]>=0x80000000):
                    array_register[int_rd]=array_register[int_res1]>>1
                    array_register[int_rd]=array_register[int_rd]|0x80000000
                    for i in range(int_shampt-1):
                        array_register[int_rd]=array_register[int_rd]>>1
                        array_register[int_rd]=array_register[int_rd]|0x80000000
                        if i>32:
                            break
                        
                    
                else:
                    array_register[int_rd]=array_register[int_res1]>>int_shampt
                    
            else:
                str_function='NoFunct'
                
            pc+=1
            return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_res1 +',' + ' ' + str_Shamt
        #Shift immediate --end--
        else:
            str_function='NoFunct'
            
        
        pc+=1
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_res1 +',' + ' ' + str_decimm
    
    return 'ERROR: I_Format'

def S_Format():
    global pc
    #print('S_Format')
    str_function=''
    if(opcode_Binary=='0100011'):
        #print('SB, SH, SW')  
        res2=full_Binary[7:12]
        res1=full_Binary[12:17] 
        funct3=full_Binary[17:20] 
        imm_first=full_Binary[0:7]
        imm_second=full_Binary[20:25]  
        str_sumimm=(imm_first+imm_second)
        int_res1=int(res1,2)
        int_res2=int(res2,2)
        
        if (str_sumimm[0]=='1'):
            int_decimm = twos_comp(int(str_sumimm,2), len(str_sumimm))
        else:
            int_decimm=int(str_sumimm,2)
            
        str_decimm=str(int_decimm)
        str_res1='x'+str(int(res1,2))
        str_res2='x'+str(int(res2,2))
        int_base_address=array_register[int_res1]

        if (int_base_address>=0x80000000):
            int_base_address=twos_comp(int_base_address, 32)

        
#        if (funct3=='000'):
#            str_function='sb'
#        elif (funct3=='001'):
#            str_function='sh'

        if (funct3=='010'):
            
            str_function='sw'
            DATA_MEMORY[int(((int_base_address+int_decimm)-0x10000000)/4)]=array_register[int_res2]

        else:
            str_function='NoFunct'
        pc+=1
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+str_function+' '+ str_res2+', '+str_decimm+'('+str_res1+')'
    return 'ERROR: S_Format'


def SB_Format():
    global pc
    #print('SB_Format')
    str_function=''
    global sb_loop
    global sb_function
    if(opcode_Binary=='1100011'):
        #print('BEQ, BNE, BLT, BGE, BLTU, BGEU')
        imm_first=full_Binary[0:7]
        imm_second=full_Binary[20:25]  
        res2=full_Binary[7:12]
        res1=full_Binary[12:17] 
        funct3=full_Binary[17:20] 

        str_imm=str(imm_first+imm_second)
        str_sumimm=(str_imm[0]+str_imm[11]+str_imm[1:7]+str_imm[7:11]+'0')
        imm=full_Binary[0:12]
        
        if (imm[0]=='1'):
            int_decimm = twos_comp(int(str_sumimm,2), len(str_sumimm))
        else:
            int_decimm=int(str_sumimm,2)
        int_res1=int(res1,2)
        int_res2=int(res2,2)
        str_decim=str(int_decimm)
        str_res1='x'+str(int(res1,2))
        str_res2='x'+str(int(res2,2))
        
        if(funct3=='000'):
            str_function='beq'
            if(array_register[int_res1]==array_register[int_res2]):
                sb_function='beq'
                sb_loop=int_decimm
                pc=pc+int(int_decimm/4)

        elif(funct3=='001'):
            str_function='bne'
            if(array_register[int_res1]!=array_register[int_res2]):
                sb_function='bne'
                sb_loop=int_decimm
                pc=pc+int(int_decimm/4)
              
        elif(funct3=='100'):
            str_function='blt'
            if(array_register[int_res1]<array_register[int_res2]):
                sb_function='blt'
                sb_loop=int_decimm
                pc=pc+int(int_decimm/4)

        elif(funct3=='101'):
            str_function='bge'
            if(array_register[int_res1]>=array_register[int_res2]):
                sb_function='bge'
                sb_loop=int_decimm
                pc=pc+int(int_decimm/4)

#        elif(funct3=='110'):
#            str_function='bltu'
#        elif(funct3=='111'):
#            str_function='bgeu'
        else:
            str_function='NoFunct'
            
        
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_res1 +',' + ' ' + str_res2 +',' + ' ' + str_decim
    return 'ERROR: SB_Format'

def R_Format():
    global pc
    #print('R_Format')
    str_function=''
    if(opcode_Binary=='0110011'):
        #print('ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND')
        
        rd=full_Binary[20:25]  
        res2=full_Binary[7:12]
        res1=full_Binary[12:17] 
        funct7=full_Binary[0:7]
        funct3=full_Binary[17:20]   
        int_res1=int(res1,2)
        
        int_res2=int(res2,2)
        int_rd=int(rd,2)
        
        str_rd='x'+str(int(rd,2))
        str_res1='x'+str(int(res1,2))
        str_res2='x'+str(int(res2,2))
 
        
 
        int_res1_register = twos_comp(array_register[int_res1], 32)
        int_res2_register = twos_comp(array_register[int_res2], 32)
        
        if (funct3=='000' and funct7=='0000000'):
            str_function='add'
            if(array_register[int_res1]+array_register[int_res2]>=0):
                array_register[int_rd]=array_register[int_res1]+array_register[int_res2]
            else:
                array_register[int_rd]=array_register[int_res1]+0xFFFFFFFF+array_register[int_res2] +1            
        elif (funct3=='000' and funct7=='0100000'):
            str_function='sub'
            if(array_register[int_res1]-array_register[int_res2]>=0):
                array_register[int_rd]=array_register[int_res1]+array_register[int_res2]
            else:
                array_register[int_rd]=array_register[int_res1]-(0xFFFFFFFF+array_register[int_res2] +1)            
            
        elif (funct3=='001' and funct7=='0000000'):
            str_function='sll'
            if array_register[int_res2]<80000000:                
                array_register[int_rd]=array_register[int_res1]<<array_register[int_res2]
            else:
                array_register[int_rd]=array_register[int_res1]
        elif (funct3=='010' and funct7=='0000000'):
            
            
            #slt가 이상해ㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐ
            
            str_function='slt'
            if (int_res1_register<int_res2_register):
                array_register[int_rd]=1
            else:
                array_register[int_rd]=0
        elif (funct3=='011' and funct7=='0000000'):
            str_function='sltu'
            if (array_register[int_res1]<array_register[int_res2]):
                array_register[int_rd]=1
            else:
                array_register[int_rd]=0
        elif (funct3=='100' and funct7=='0000000'):
            str_function='xor'
            array_register[int_rd]=array_register[int_res1]^array_register[int_res2]
        elif (funct3=='101' and funct7=='0000000'):
            str_function='srl'
            array_register[int_rd]=array_register[int_res1]>>array_register[int_res2]
        elif (funct3=='101' and funct7=='0100000'):
            str_function='sra'
            if(array_register[int_res1]>=0x80000000):
                array_register[int_rd]=array_register[int_res1]>>1
                array_register[int_rd]=array_register[int_rd]|0x80000000
                for i in range(array_register[int_res2]):
                    array_register[int_rd]=array_register[int_rd]>>1
                    array_register[int_rd]=array_register[int_rd]|0x80000000
                    if i>32:
                        break
            else:
                array_register[int_rd]=array_register[int_res1]>>array_register[int_res2]          
        elif (funct3=='110' and funct7=='0000000'):
            str_function='or'
            array_register[int_rd]=array_register[int_res1]|array_register[int_res2]
            
        elif (funct3=='111' and funct7=='0000000'):
            str_function='and'
            array_register[int_rd]=array_register[int_res1]&array_register[int_res2]
        pc+=1
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_rd  +',' + ' ' + str_res1 +',' + ' ' + str_res2
    return 'Error: R_Format'

###################

#filename1 = sys.argv[1]
#filename2 = sys.argv[2]

argv=[0,"proj2_7_inst.bin","proj2_7_data.bin",73,None]

#with open(filename1, 'rb') as file1:
with open(argv[1], 'rb') as file1:
    
    # read 4byte (32bit)
    line=file1.read(4)
#    with open(filename2, 'rb') as file2:
#    num_count=int(file2)    
    global opcode_Binary        
    global str_count
    global full_Binary
    global str_HexFullBinary

    
    if isinstance(argv[3], int):
        num_count=argv[3]
        with open(argv[2], 'rb') as file2:   
            
            line2=file2.read(4) #data memory

            for i in range(4):
                DATA_MEMORY[i]=int.from_bytes(line2, byteorder='little')
                line2=file2.read(4)
                        
            while line and num_count:

                sb_loop=0
                str_count=str(count)
                sb_function=''
                
                # save 32bit binary to string
                input_file=format(int.from_bytes(line, byteorder='little'),'b')
                input_file =input_file.zfill(32)
                full_Binary=input_file[0:32]   
                
                #global str_HexFullBinary
                str_HexFullBinary=str(format(int(full_Binary,2),'x').zfill(8))

                #check opcode
                opcode_Binary = full_Binary[25:32]
                            #0x37, 0x17, 0x6F, 
                            #0x67, 0x03, 0x13, 
                            #0x63, 0x23, 0x33
                functions={'0110111':U_Format,'0010111':U_Format,'1101111':UJ_Format, 
                            '1100111':I_Format,'0000011':I_Format,'0010011':I_Format,
                            '1100011':SB_Format,'0100011':S_Format,'0110011':R_Format
                            }
                
                #print('inst '+str_count+': '+str_HexFullBinary,'functions: '+opcode_Binary)
                # call function. if error : unkown instruction
                try:
                    if (int(full_Binary,2)==19):
                        break
                    print(functions[opcode_Binary]())
                except:
                    print('inst '+str_count+': '+str_HexFullBinary+' unknown instruction')
                    
                count+=1
                num_count=num_count-1
                # read next

                if sb_function=='bne':
                    file1.seek(file1.tell()-4+sb_loop)
                elif sb_function=='beq':
                    file1.seek(file1.tell()-4+sb_loop)
                elif sb_function=='blt':
                    file1.seek(file1.tell()-4+sb_loop)
                elif sb_function=='bge':
                    file1.seek(file1.tell()-4+sb_loop)
                
                line=file1.read(4)   
                for i in range(32):

                    array_register[i]=array_register[i] & 0xffffffff
    else:
        num_count=argv[2]
        while line and num_count:

                sb_loop=0
                str_count=str(count)
                sb_function=''
                
                # save 32bit binary to string
                input_file=format(int.from_bytes(line, byteorder='little'),'b')
                input_file =input_file.zfill(32)
                full_Binary=input_file[0:32]   
                
                
                
                #global str_HexFullBinary
                str_HexFullBinary=str(format(int(full_Binary,2),'x').zfill(8))

                print(str_HexFullBinary)
                #check opcode
                opcode_Binary = full_Binary[25:32]
                            #0x37, 0x17, 0x6F, 
                            #0x67, 0x03, 0x13, 
                            #0x63, 0x23, 0x33
                functions={'0110111':U_Format,'0010111':U_Format,'1101111':UJ_Format, 
                            '1100111':I_Format,'0000011':I_Format,'0010011':I_Format,
                            '1100011':SB_Format,'0100011':S_Format,'0110011':R_Format
                            }
                
                #print('inst '+str_count+': '+str_HexFullBinary,'functions: '+opcode_Binary)
                # call function. if error : unkown instruction
                try:
#                    if (int(full_Binary,2)==19):
#                        break
                    print(functions[opcode_Binary]())
                except:
                    print('inst '+str_count+': '+str_HexFullBinary+' unknown instruction')
                    
                count+=1
                num_count=num_count-1
                # read next

                if sb_function=='bne':
                    file1.seek(file1.tell()-4+sb_loop)
                elif sb_function=='beq':
                    file1.seek(file1.tell()-4+sb_loop)
                elif sb_function=='blt':
                    file1.seek(file1.tell()-4+sb_loop)
                elif sb_function=='bge':
                    file1.seek(file1.tell()-4+sb_loop)
                
                line=file1.read(4)   
                
                for i in range(32):

                    array_register[i]=array_register[i] & 0xffffffff
                    

    for i in range(32):
        print('x'+str(i)+': '+"0x{:08x}".format(array_register[i]))

