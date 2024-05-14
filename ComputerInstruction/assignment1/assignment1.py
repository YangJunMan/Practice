import sys



# change 2's complement to decimal
def twos_comp(value, bits):
    if (value & (1 << (bits - 1))) != 0:
        value = value - (1 << bits)   
    return value                    

    
count=0
def U_Format():
    #print('U_Format')
    str_function=''
    if(opcode_Binary=='0110111'):
        #print('LUI')
        str_function='lui'
        imm = full_Binary[0:20]
        rd = full_Binary[20:25]
        if (imm[0]=='1'):
            int_decimm = twos_comp(int(imm,2), len(imm))
        else:
            int_decimm=int(imm,2)      
            #shoud be 2^12.  
        int_decimm=int_decimm<<12
        
        str_decimm=str(int_decimm)
        dec_Rd=int(rd,2)
        str_Rd='x'+str(dec_Rd)
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_decimm
    elif(opcode_Binary=='0010111'):
        #print('AUIPC')
        str_function='auipc'
        imm = full_Binary[0:20]
        rd = full_Binary[20:25]
        
        
        
        if (imm[0]=='1'):
            int_decimm = twos_comp(int(imm,2), len(imm))
        else:
            int_decimm=int(imm,2)        
        
                
        int_decimm=int_decimm<<12
        
        str_decimm=str(int_decimm)
        dec_Rd=int(rd,2)
        str_Rd='x'+str(dec_Rd)
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_decimm
        
    return 'ERROR: U_Format'

def UJ_Format():
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
        
        str_Rd='x'+str(int(rd,2))
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_decimm
    return 'Error: J_Format'
    
def I_Format():
    #print('I_Format')
    str_function=''
    
    if(opcode_Binary=='1100111'):
        #print('JALR')
        str_function='jalr'
        offset=full_Binary[0:12]
        rs1=full_Binary[12:17]
        rd = full_Binary[20:25]
        
        str_Rd='x'+str(int(rd,2))
        if (offset[0]=='1'):
            str_offset = twos_comp(int(offset,2), len(offset))
        else:
            str_offset=str(int(offset,2))

        str_Rs1='x'+str(int(rs1,2))
        
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_offset+'('+str_Rs1+')'
    elif(opcode_Binary=='0000011'):
        #print('LB, LH, LW, LBU, LHU')
        str_function=''
        
        imm=full_Binary[0:12]
        if (imm[0]=='1'):
            int_decimm = twos_comp(int(imm,2), len(imm))
        else:
            int_decimm=int(imm,2)
        
        
        str_decimm=str(int_decimm)  
        res1=full_Binary[12:17] 
        funct3=full_Binary[17:20]   
        str_res1='x'+str(int(res1,2))
        rd=full_Binary[20:25]  
        str_Rd='x'+str(int(rd,2))
        
        if(funct3=='000'):
            str_function='lb'
        elif(funct3=='001'):
            str_function='lh'
        elif(funct3=='010'):
            str_function='lw'
        elif(funct3=='100'):
            str_function='lbu'
        elif(funct3=='101'):
            str_function='lhu'
        else:
            str_function='NoFunct'
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_decimm + '(' + str_res1+ ')'
    elif(opcode_Binary=='0010011'):
        #print('ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI')
        imm=full_Binary[0:12]
        res1=full_Binary[12:17]
        funct3=full_Binary[17:20]
        rd=full_Binary[20:25]
        
        if (imm[0]=='1'):
            int_decimm = twos_comp(int(imm,2), len(imm))
        else:
            int_decimm=int(imm,2)
        
        str_decimm=str(int_decimm)
        str_res1='x'+str(int(res1,2))
        str_Rd='x'+str(int(rd,2))

        if(funct3=='000'):
            str_function='addi'
        elif(funct3=='010'):
            str_function='slti'
        elif(funct3=='011'):
            str_function='sltiu'
        elif(funct3=='100'):
            str_function='xori'
        elif(funct3=='110'):
            str_function='ori'
        elif(funct3=='111'):
            str_function='andi'           
        
        #Shift immediate 명령어
        elif(funct3=='101' or funct3=='001'):
            if(funct3=='001'):
                str_function='slli'
            elif(imm[0:6]=='000000'):
                str_function='srli'
            elif(imm[0:6]=='010000'):
                str_function='srai'
            else:
                str_function='NoFunct'
                
            str_Shamt=str(int(imm[6:12],2)) 

            return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_res1 +',' + ' ' + str_Shamt
        #Shift immediate --end--
        else:
            str_function='NoFunct'
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_Rd +',' + ' ' + str_res1 +',' + ' ' + str_decimm
    
    return 'ERROR: I_Format'

def S_Format():
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
        
        if (str_sumimm[0]=='1'):
            int_decimm = twos_comp(int(str_sumimm,2), len(str_sumimm))
        else:
            int_decimm=int(str_sumimm,2)
            
        str_decimm=str(int_decimm)
        str_res1='x'+str(int(res1,2))
        str_res2='x'+str(int(res2,2))
        if (funct3=='000'):
            str_function='sb'
        elif (funct3=='001'):
            str_function='sh'
        elif (funct3=='010'):
            str_function='sw'
        else:
            str_function='NoFunct'
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+str_function+' '+ str_res2+', '+str_decimm+'('+str_res1+')'
    return 'ERROR: S_Format'


def SB_Format():
    #print('SB_Format')
    str_function=''
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
        
        str_decim=str(int_decimm)
        str_res1='x'+str(int(res1,2))
        str_res2='x'+str(int(res2,2))
        if(funct3=='000'):
            str_function='beq'
        elif(funct3=='001'):
            str_function='bne'
        elif(funct3=='100'):
            str_function='blt'
        elif(funct3=='101'):
            str_function='bge'
        elif(funct3=='110'):
            str_function='bltu'
        elif(funct3=='111'):
            str_function='bgeu'
        else:
            str_function='NoFunct'
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_res1 +',' + ' ' + str_res2 +',' + ' ' + str_decim
    return 'ERROR: SB_Format'

def R_Format():
    #print('R_Format')
    str_function=''
    if(opcode_Binary=='0110011'):
        #print('ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND')
        
        rd=full_Binary[20:25]  
        res2=full_Binary[7:12]
        res1=full_Binary[12:17] 
        funct7=full_Binary[0:7]
        funct3=full_Binary[17:20]   
        
        str_rd='x'+str(int(rd,2))
        str_res1='x'+str(int(res1,2))
        str_res2='x'+str(int(res2,2))
        if (funct3=='000' and funct7=='0000000'):
            str_function='add'
        elif (funct3=='000' and funct7=='0100000'):
            str_function='sub'
        elif (funct3=='001' and funct7=='0000000'):
            str_function='sll'
        elif (funct3=='010' and funct7=='0000000'):
            str_function='slt'
        elif (funct3=='011' and funct7=='0000000'):
            str_function='sltu'
        elif (funct3=='100' and funct7=='0000000'):
            str_function='xor'
        elif (funct3=='101' and funct7=='0000000'):
            str_function='srl'
        elif (funct3=='101' and funct7=='0100000'):
            str_function='sra'
        elif (funct3=='110' and funct7=='0000000'):
            str_function='or'
        elif (funct3=='111' and funct7=='0000000'):
            str_function='and'
        
        return 'inst '+str_count+': '+ str_HexFullBinary+' '+ str_function + ' ' + str_rd  +',' + ' ' + str_res1 +',' + ' ' + str_res2
    return 'Error: R_Format'

###################

filename = sys.argv[1]

with open(filename, 'rb') as file:


    # read 4byte (32bit)
    line=file.read(4)
        
    while line:
        global opcode_Binary        
        global str_count
        global full_Binary
        global str_HexFullBinary
        str_count=str(count)
        
        # save 32bit binary to string
        line=format(int.from_bytes(line, byteorder='little'),'b')
        line =line.zfill(32)
        full_Binary=line[0:32]   
         
        #global str_HexFullBinary
        str_HexFullBinary=str(format(int(full_Binary,2),'x').zfill(8))
        
        #check opcode
        opcode_Binary = line[25:32]
                    #0x37, 0x17, 0x6F, 
                    #0x67, 0x03, 0x13, 
                    #0x63, 0x23, 0x33
        functions={'0110111':U_Format,'0010111':U_Format,'1101111':UJ_Format, 
                   '1100111':I_Format,'0000011':I_Format,'0010011':I_Format,
                   '1100011':SB_Format,'0100011':S_Format,'0110011':R_Format
                   }
        
        # call function. if error : unkown instruction
        try:
            print(functions[opcode_Binary]())
        except:
            print('inst '+str_count+': '+str_HexFullBinary+' unknown instruction')
        count+=1
        # read next
        line=file.read(4)