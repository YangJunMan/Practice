package Basic.review.ExerciseCal;

import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;
import javax.swing.LayoutStyle.ComponentPlacement;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextArea;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;

public class Main implements ActionListener{
	// 각종 프레임, 라벨 및 버튼 추가
	private JFrame frame;
	//상단 이미지
	private JLabel Lable_LOGO;
	//상단 텍스트
	private JLabel Label_TXT;
	//상단 패널
	private JPanel panel_1;
	//하단 패널
	private	JPanel panel_2;
	//출력AREA
	private JTextArea Display_Area;
	//버튼들
	private JButton btn_1;
	private JButton btn_2;
	private JButton btn_3;
	private JButton btn_4;
	private JButton btn_5;
	private JButton btn_6;
	private JButton btn_7;
	private JButton btn_8;
	private JButton btn_9;
	private JButton btn_0;
	private JButton btn_Swimming;
    private JButton btn_Jogging;
    private JButton btn_Tennis;
    private JButton btn_Badminton;
    private JButton btn_CANCLE;
    private JButton btn_CLEAR;
    private JButton btn_ENTER;
	private JButton btn_Yes;
	private JButton btn_No;

	int sum=0;
	//생성된 배열의 개수를 카운트해 저장. CANCLE입력시 0으로 초기화
	int count=0;
	// CalorieInterface 의 내용을 저장하기 위한 배열
	// Lecture 6 Interface 참고
	CalorieInterface[] calorieObject = new CalorieInterface[200];

	

	
	public static void main(String[] args) {

		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					
					Main window = new Main();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * eclipse windows builder를 이용하여 생성
	 * 무한 반복 실행
	 *
	 */
	public Main() {
		initialize();
	}

	/**
	 * eclipse windows builder를 이용하여 생성
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 510, 700);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setTitle("Fitness Planner");
		frame.setResizable(false);
		frame.setLocationRelativeTo(null);


	//윗 패널, 아랫 패널로 나눠봄
		panel_1 = new JPanel();
		panel_2 = new JPanel();

	// GroupLayout을 이용하여 각각의 패널을 정렬. GroupLayout은 윈도우 빌더에서 사용하는 레이아웃..
		GroupLayout groupLayout = new GroupLayout(frame.getContentPane());
		groupLayout.setHorizontalGroup(
			groupLayout.createParallelGroup(Alignment.TRAILING)
				.addGroup(Alignment.LEADING, groupLayout.createSequentialGroup()
					.addContainerGap()
					.addGroup(groupLayout.createParallelGroup(Alignment.TRAILING, false)
						.addComponent(panel_1, Alignment.LEADING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
						.addComponent(panel_2, Alignment.LEADING, GroupLayout.DEFAULT_SIZE, 478, Short.MAX_VALUE))
					.addContainerGap())
		);
		groupLayout.setVerticalGroup(
			groupLayout.createParallelGroup(Alignment.LEADING)
				.addGroup(groupLayout.createSequentialGroup()
					.addContainerGap()
					.addComponent(panel_1, GroupLayout.PREFERRED_SIZE, 386, GroupLayout.PREFERRED_SIZE)
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(panel_2, GroupLayout.DEFAULT_SIZE, 260, Short.MAX_VALUE)
					.addGap(1))
		);

	// 패널의 레이아웃을 null로 설정. 원하는 곳에 배치할거에요~^^
		panel_1.setLayout(null);
		panel_2.setLayout(null);


	// 이미지, 출력패널, 기능버튼
		Label_TXT = new JLabel("Fitness Planner");
		Label_TXT.setHorizontalAlignment(SwingConstants.CENTER);
		Label_TXT.setFont(new Font("굴림", Font.BOLD, 13));
		Label_TXT.setBounds(116, 112, 265, 27);
		panel_1.add(Label_TXT);

		Lable_LOGO = new JLabel("");
		Lable_LOGO.setIcon(new ImageIcon(Main.class.getResource("/assets/fitness_planner_logo.png")));
		Lable_LOGO.setBounds(87, 29, 333, 73);
		panel_1.add(Lable_LOGO);

		Display_Area = new JTextArea();
		Display_Area.setEditable(false);
		Display_Area.setBounds(119, 150, 265, 236);
		panel_1.add(Display_Area);

		btn_Swimming = new JButton("Swimming");
		btn_Swimming.setHorizontalAlignment(SwingConstants.LEFT);
		btn_Swimming.setFont(new Font("굴림", Font.BOLD, 10));
		btn_Swimming.setIcon(new ImageIcon(Main.class.getResource("/assets/swimming.png")));
		btn_Swimming.setBounds(0, 187, 119, 40);
		panel_1.add(btn_Swimming);
		
		btn_Jogging = new JButton("Jogging");
		btn_Jogging.setHorizontalAlignment(SwingConstants.LEFT);
		btn_Jogging.setIcon(new ImageIcon(Main.class.getResource("/assets/jogging.png")));
		btn_Jogging.setFont(new Font("굴림", Font.BOLD, 10));
		btn_Jogging.setBounds(0, 225, 119, 40);
		panel_1.add(btn_Jogging);
		
		btn_Tennis = new JButton("Tennis");
		btn_Tennis.setHorizontalAlignment(SwingConstants.LEFT);
		btn_Tennis.setIcon(new ImageIcon(Main.class.getResource("/assets/tennis.png")));
		btn_Tennis.setFont(new Font("굴림", Font.BOLD, 10));
		btn_Tennis.setBounds(0, 263, 119, 40);
		panel_1.add(btn_Tennis);
		
		btn_Badminton = new JButton("Badminton");
		btn_Badminton.setHorizontalAlignment(SwingConstants.LEFT);
		btn_Badminton.setIcon(new ImageIcon(Main.class.getResource("/assets/badminton.png")));
		btn_Badminton.setFont(new Font("굴림", Font.BOLD, 10));
		btn_Badminton.setBounds(0, 301, 119, 40);
		panel_1.add(btn_Badminton);
		
		btn_Yes = new JButton("Yes");
		btn_Yes.setFont(new Font("굴림", Font.BOLD, 11));
		btn_Yes.setIcon(new ImageIcon(Main.class.getResource("/assets/enterSmall.png")));
		btn_Yes.setBounds(384, 237, 81, 35);
		panel_1.add(btn_Yes);
		
		btn_No = new JButton("No");
		btn_No.setFont(new Font("굴림", Font.BOLD, 11));
		btn_No.setIcon(new ImageIcon(Main.class.getResource("/assets/cancelSmall.png")));
		btn_No.setBounds(384, 269, 81, 35);
		panel_1.add(btn_No);
		
		btn_CANCLE = new JButton("CANCLE");
		btn_CANCLE.setFont(new Font("굴림", Font.BOLD, 11));
		btn_CANCLE.setHorizontalAlignment(SwingConstants.LEFT);
		btn_CANCLE.setIcon(new ImageIcon(Main.class.getResource("/assets/cancel.png")));
		btn_CANCLE.setBounds(330, 0, 139, 60);
		panel_2.add(btn_CANCLE);
		
		btn_CLEAR = new JButton("CLEAR");
		btn_CLEAR.setFont(new Font("굴림", Font.BOLD, 11));
		btn_CLEAR.setHorizontalAlignment(SwingConstants.LEFT);
		btn_CLEAR.setIcon(new ImageIcon(Main.class.getResource("/assets/clear.png")));
		btn_CLEAR.setBounds(330, 58, 139, 60);
		panel_2.add(btn_CLEAR);
		
		btn_ENTER = new JButton("ENTER");
		btn_ENTER.setFont(new Font("굴림", Font.BOLD, 11));
		btn_ENTER.setHorizontalAlignment(SwingConstants.LEFT);
		btn_ENTER.setIcon(new ImageIcon(Main.class.getResource("/assets/enter.png")));
		btn_ENTER.setBounds(330, 116, 139, 60);
		panel_2.add(btn_ENTER);
	//end of 이미지, 출력패널, 기능버튼

	// 숫자버튼
		
		btn_1 = new JButton("");
		btn_1.setIcon(new ImageIcon(Main.class.getResource("/assets/1.png")));
		btn_1.setBounds(78, 0, 85, 60);
		panel_2.add(btn_1);
		
		btn_2 = new JButton("");
		btn_2.setIcon(new ImageIcon(Main.class.getResource("/assets/2.png")));
		btn_2.setBounds(162, 0, 85, 60);
		panel_2.add(btn_2);
		

		btn_3 = new JButton("");
		btn_3.setIcon(new ImageIcon(Main.class.getResource("/assets/3.png")));
		btn_3.setBounds(246, 0, 85, 60);
		panel_2.add(btn_3);
		
		
		btn_4 = new JButton("");
		btn_4.setIcon(new ImageIcon(Main.class.getResource("/assets/4.png")));
		btn_4.setBounds(78, 58, 85, 60);
		panel_2.add(btn_4);
		
		btn_5 = new JButton("");
		btn_5.setIcon(new ImageIcon(Main.class.getResource("/assets/5.png")));
		btn_5.setBounds(162, 58, 85, 60);
		panel_2.add(btn_5);
		
		btn_6 = new JButton("");
		btn_6.setIcon(new ImageIcon(Main.class.getResource("/assets/6.png")));
		btn_6.setBounds(246, 58, 85, 60);
		panel_2.add(btn_6);

		btn_7 = new JButton("");
		btn_7.setIcon(new ImageIcon(Main.class.getResource("/assets/7.png")));
		btn_7.setBounds(78, 116, 85, 60);
		panel_2.add(btn_7);
		
		btn_8 = new JButton("");
		btn_8.setIcon(new ImageIcon(Main.class.getResource("/assets/8.png")));
		btn_8.setBounds(162, 116, 85, 60);
		panel_2.add(btn_8);

		btn_9= new JButton("");
		btn_9.setIcon(new ImageIcon(Main.class.getResource("/assets/9.png")));
		btn_9.setBounds(246, 116, 85, 60);
		panel_2.add(btn_9);

		
		btn_0 = new JButton("");
		btn_0.setIcon(new ImageIcon(Main.class.getResource("/assets/0.png")));
		btn_0.setBounds(162, 175, 85, 60);
		panel_2.add(btn_0);

	//end of 숫자버튼

		Display_Area.setText("Choose Excerise (from left menu):");
		frame.getContentPane().setLayout(groupLayout);

	//버튼에 액션 리스너 추가
		btn_1.addActionListener(this);
		btn_2.addActionListener(this);
		btn_3.addActionListener(this);
		btn_4.addActionListener(this);
		btn_5.addActionListener(this);
		btn_6.addActionListener(this);
		btn_7.addActionListener(this);
		btn_8.addActionListener(this);
		btn_9.addActionListener(this);
		btn_0.addActionListener(this);
		btn_CANCLE.addActionListener(this);
		btn_CLEAR.addActionListener(this);
		btn_ENTER.addActionListener(this);
		btn_Yes.addActionListener(this);
		btn_No.addActionListener(this);
		btn_Swimming.addActionListener(this);
		btn_Jogging.addActionListener(this);
		btn_Tennis.addActionListener(this);
		btn_Badminton.addActionListener(this);
		
	}
	// 버튼을 눌렀을 때의 동작을 정의
	@Override
	public void actionPerformed(ActionEvent e) {

	// 숫자 버튼을 누르면 화면에 숫자를 계속 추가함.
		if (e.getSource() == btn_1 ) {
			Display_Area.setText(Display_Area.getText() + 1);
		} else if(e.getSource() == btn_2) {
			Display_Area.setText(Display_Area.getText() + 2);
		} else if(e.getSource() == btn_3) {
			Display_Area.setText(Display_Area.getText() + 3);
		}else if (e.getSource() == btn_4) {
			Display_Area.setText(Display_Area.getText() + 4);
		} else if (e.getSource() == btn_5) {
			Display_Area.setText(Display_Area.getText() + 5);
		} else if (e.getSource() == btn_6) {
			Display_Area.setText(Display_Area.getText() + 6);
		} else if (e.getSource() == btn_7) {
			Display_Area.setText(Display_Area.getText() + 7);
		} else if (e.getSource() == btn_8) {
			Display_Area.setText(Display_Area.getText() + 8);
		} else if (e.getSource() == btn_9) {
			Display_Area.setText(Display_Area.getText() + 9);
		} else if (e.getSource() == btn_0) {
			Display_Area.setText(Display_Area.getText() + 0);
		}


	// else 는 숫자가 아닌 다른 버튼을 눌렀을 때의 동작을 정의
		else{
 		if (e.getSource() == btn_Swimming) {
			count++;
			// calorieObject에 저장된 정보를 Swimming으로 형변환하여 저장.. Lecture 6 Interface 참고

			calorieObject[count] = new Swimming(0,new Course(0,0));
			Display_Area.setText(
					"Swimming"+"\n"+
					"Enter Calories Per Distance (Kcal / Km) :");
			
		} else if (e.getSource() == btn_Jogging) {// 동일
			count++;
			calorieObject[count] = new Jogging(0,new Course(0,0));
			Display_Area.setText(
					"Jogging"+"\n"+
					"Enter Calories Per Distance (Kcal / Km) :");

		} else if (e.getSource() == btn_Tennis) {// 동일
			count++;
			calorieObject[count] = new Tennis(0,0,new Match(0,0));
			Display_Area.setText(
					"Tennis"+"\n"+
					"Enter Number of Matches :");
		} else if (e.getSource() == btn_Badminton) {// 동일
			count++;
			calorieObject[count] = new Badminton(0,0,new Match(0,0));
			Display_Area.setText(
					"Badminton"+"\n"+
					"Enter Number of Matches :");
		}
		// 취소 버튼을 누르면 초기화
		else if (e.getSource() == btn_CANCLE) {
			Display_Area.setText(
					"Cancled!"+"\n"+
					"New plan:"+"\n"+
					"Choose Excerise (from left menu):"
			);
			count=0;

		// clear 버튼을 누르면 숫자 지우기
		} else if (e.getSource() == btn_CLEAR) {
			Display_Area.setText(Display_Area.getText().replaceAll("[0-9]",""));

		}


		// 엔터를 누르면 화면의 숫자를 인식해서 배열에 저장합니다.
		else if (e.getSource() == btn_ENTER) {
			// 숫자만 인식하기
			String instStr= Display_Area.getText().replaceAll("[^0-9]", "");
			double inst = Integer.parseInt(instStr.trim());
			// 여기서부터는 Course를 사용하는 Swimming, Jogging
			if(calorieObject[count] instanceof Swimming) {
				// 칼로리 소모량을 입력받기
				if(((Swimming) calorieObject[count]).getCourse().getCaloriePerDistance()==0) {
					((Swimming) calorieObject[count]).getCourse().setCaloriePerDistance(inst);
					Display_Area.setText("Enter Distance (Km) :");
				}
				// 거리를 입력받기
				else if(((Swimming) calorieObject[count]).getCourse().getDistance()==0){
					((Swimming) calorieObject[count]).getCourse().setDistance(inst);
				// 칼로리 계산
					((Swimming) calorieObject[count]).calcuateCalories();
					Display_Area.setText("Add more excercise? (from right menu)(Yes/No)");
				}

			}else if (calorieObject[count] instanceof Jogging){
				if(((Jogging) calorieObject[count]).getCourse().getCaloriePerDistance()==0) {
					((Jogging) calorieObject[count]).getCourse().setCaloriePerDistance(inst);
					Display_Area.setText("Enter Distance (Km) :");
				}
				// 거리를 입력받기
				else if(((Jogging) calorieObject[count]).getCourse().getDistance()==0){
					((Jogging) calorieObject[count]).getCourse().setDistance(inst);
					// 칼로리 계산
					((Jogging) calorieObject[count]).calcuateCalories();
					Display_Area.setText("Add more excercise? (from right menu)(Yes/No)");
				}
		// 여기서부터는 Match를 사용하는 Tennis, Badminton
			} else if (calorieObject[count] instanceof Tennis){
				// 칼로리 소모량을 입력받기

			// 매치 횟수 입력받기
				if(((Tennis) calorieObject[count]).getNumMatches()==0){
					((Tennis) calorieObject[count]).setNumMatches((int)inst);
					Display_Area.setText("Enter Calories Per set (Kcal / Km) :");
				}else if(((Tennis) calorieObject[count]).getMatch().getCaloriePerDistance()==0) {
					((Tennis) calorieObject[count]).getMatch().setCaloriePerDistance(inst);
					Display_Area.setText("Enter Number of sets :");
				}
			// 세트 수 입력받기
				else if(((Tennis) calorieObject[count]).getMatch().getNumSets()==0){
					((Tennis) calorieObject[count]).getMatch().setNumSets((int)inst);

					// 칼로리 계산
					((Tennis) calorieObject[count]).calcuateCalories();
					Display_Area.setText("Add more excercise? (from right menu)(Yes/No)");
				}

			} else if (calorieObject[count] instanceof Badminton) {
			// 매치 횟수 입력받기
				if(((Badminton) calorieObject[count]).getNumMatches()==0){
					((Badminton) calorieObject[count]).setNumMatches((int)inst);
					Display_Area.setText("Enter Calories Per set (Kcal / Km) :");
			// 세트당 칼로리 입력받기
				}else if(((Badminton) calorieObject[count]).getMatch().getCaloriePerDistance()==0) {
					((Badminton) calorieObject[count]).getMatch().setCaloriePerDistance(inst);
					Display_Area.setText("Enter Number of sets :");
				}
			// 세트 수 입력받기
				else if(((Badminton) calorieObject[count]).getMatch().getNumSets()==0){
					((Badminton) calorieObject[count]).getMatch().setNumSets((int)inst);

					// 칼로리 계산
					((Badminton) calorieObject[count]).calcuateCalories();
					Display_Area.setText("Add more excercise? (from right menu)(Yes/No)");
				}
			}


		}//Yes를 누르면 다시 excercise를 선택하라는 문구 출력
		else if (e.getSource() == btn_Yes) {
			Display_Area.setText("Choose Excerise (from left menu):");
		}
		// no 버튼을 누르면 count의 개수만큼 반복문을 돌려서 calorieObject에 저장된 정보를 출력하고, 토탈 출력
		else if (e.getSource() == btn_No) {
			Display_Area.setText("");
			if (count==0){
				Display_Area.setText("No excercise added!"+"\n"+
						"Choose Excerise (from left menu):");
			}
			else {
				//출력 및 총 칼로리 계산
				for (int i = 1; i <= count; i++) {
					Display_Area.setText(
							Display_Area.getText() +
									"Exercise : " + calorieObject[i].getClass().getSimpleName() + "\n" +
									"Consumed Calories : " + calorieObject[i].getConsumedCalories() +"\n");

					sum = sum + (int) calorieObject[i].getConsumedCalories();
				}
				//총 칼로리 출력
				Display_Area.setText(
						Display_Area.getText()  +
								"==================================================" + "\n" +
								"Total Calories Consumed : " + sum + "\n");
			}

		}

		
		
	}
		
		
        
	}
}

