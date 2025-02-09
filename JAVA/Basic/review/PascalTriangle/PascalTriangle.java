package Basic.review.PascalTriangle;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.List;
import java.util.concurrent.CancellationException;
import java.util.concurrent.ExecutionException;

public class PascalTriangle extends JFrame {

    // 이 곳에서 area와 버튼 등 미리 선언 해 놔야, 액션리스너 쉽게 사용 가능.
    private JTextArea textArea;
    private JTextField textField;
    private JButton actionButton, cancelButton;
    private JProgressBar progressBar;
    private JLabel sumLabel;
    private PascalWorker worker;

    public PascalTriangle() {
        // 제목 설정. 사이즈 설정
        setTitle("Finding Pascal's Triangle sum");
        setSize(600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // 메뉴 바. + Jmenu에 들어갈 내용들
        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        JMenuItem openItem = new JMenuItem("Open");
        JMenuItem saveItem = new JMenuItem("Save");
        JMenuItem exitItem = new JMenuItem("Exit");
        
        // 액션 리스너에 작동하도록 설정
        openItem.addActionListener(new OpenAction());
        saveItem.addActionListener(new SaveAction());
        exitItem.addActionListener(e -> System.exit(0));

        fileMenu.add(openItem);
        fileMenu.add(saveItem);
        fileMenu.add(exitItem);
        menuBar.add(fileMenu);


        //도움말 메뉴
        JMenu helpMenu = new JMenu("Help");
        JMenuItem helpItem = new JMenuItem("Help");
        helpItem.addActionListener(new HelpAction());
        helpMenu.add(helpItem);
        menuBar.add(helpMenu);
        setJMenuBar(menuBar);

        // 패널 생성 및 버튼UI 요소 추가
        JPanel panel = new JPanel();
        textField = new JTextField(5);
        actionButton = new JButton("Get Sum of Pascal's Triangle");
        cancelButton = new JButton("Cancel");
        // 처음에는 cancel 버튼을 false로 비활성화
        cancelButton.setEnabled(false);
        
        // pdf의 이미지 대로 버튼 내용, 순서 설정
        panel.add(new JLabel("Number of rows in Pascal's Triangle: "));
        // 순서대로 대입
        panel.add(textField);
        panel.add(actionButton);
        panel.add(cancelButton);

        // 파스칼을 출력할 area
        textArea = new JTextArea();
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);

        // 진행도 bar.
        progressBar = new JProgressBar();
        progressBar.setStringPainted(true);
        // 합계를 보여줄 라벨.
        sumLabel = new JLabel("Sum =  0");

        // 하단 패널에 bar와 라벨 추가.
        JPanel bottomPanel = new JPanel(new BorderLayout());
        bottomPanel.add(progressBar, BorderLayout.CENTER);
        bottomPanel.add(sumLabel, BorderLayout.EAST);

        // 순서대로 넣기
        add(panel, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);
        add(bottomPanel, BorderLayout.SOUTH);

        // 각 버튼들에 액션 리스너 추가.
        actionButton.addActionListener(new ActionButtonListener());
        cancelButton.addActionListener(new CancelButtonListener());

        setVisible(true);
    }

    // 본격 Pascal 삼각형을 출력할 액션 벝튼 리스너
    private class ActionButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            textArea.setText("");
            sumLabel.setText("Sum =  0");
            progressBar.setValue(0);
            // 1~20줄 까지만 입력 받기
            try {
                int rows = Integer.parseInt(textField.getText());
                if (rows < 1 || rows > 20) throw new NumberFormatException();
                worker = new PascalWorker(rows);
                // 본격 실행!
                worker.execute();
                actionButton.setEnabled(false);
                cancelButton.setEnabled(true);
            } catch (NumberFormatException ex) { // input 에러 발생 시 출력할 메세지
                JOptionPane.showMessageDialog(
                        PascalTriangle.this, 
                        "Please enter valid input!",
                        "Warning", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    // 취소 버튼
    private class CancelButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            // 만약 worker가 실행 중( null이 아님 ) 이거나, isdone이 실행되지 않았을 때
            if (worker != null && !worker.isDone()) {
                worker.cancel(true);
            }
        }
    }
    
    // 파일 열기
    private class OpenAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JFileChooser fileChooser = new JFileChooser();
            int option = fileChooser.showOpenDialog(PascalTriangle.this);
            if (option == JFileChooser.APPROVE_OPTION) {
                File file = fileChooser.getSelectedFile();
                loadFromFile(file);
            }
        }
    }
    // 파일 저장하기
    private class SaveAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JFileChooser fileChooser = new JFileChooser();
            int option = fileChooser.showSaveDialog(PascalTriangle.this);
            if (option == JFileChooser.APPROVE_OPTION) {
                File file = fileChooser.getSelectedFile();
                saveToFile(file);
            }
        }
    }

    // help 도움말 버튼 누를 시
    private class HelpAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JOptionPane.showMessageDialog(PascalTriangle.this,
                    "This program generates Pascal's Triangle up to given number of rows. " +
                            "Use the buttons to open or save files, and for help information.",
                    "Help", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    private void saveToFile(File file) {
        // textarea으이 내용들을 받아서 파일에 작성
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            writer.write(textArea.getText());
        } // 파일 작성 도중 에러 발생시 에러 출력
        catch (IOException ex) {
            JOptionPane.showMessageDialog(this,
                    "Error. saving file ",
                    "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    //파일 읽을 때
    private void loadFromFile(File file) {
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            // 영역 초기화
            textArea.setText("");
            String line;
            // 파일의 각 줄들을 순서대로 출력
            while ((line = reader.readLine()) != null) {
                textArea.append(line + "\n");
            }
            // 파일을 모두 읽었으면 진행상황은 100이다!
            progressBar.setValue(100);

            int rows = (int) textArea.getText().lines().count();
            textField.setText(String.valueOf(rows));
        } catch (IOException ex) {
            // 파일 읽기 도중 에러 발생시
            JOptionPane.showMessageDialog(this,
                    "Error loading file: " + ex.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private class PascalWorker extends SwingWorker<Integer, Object[]> {
        private final int rows;
        
        // rows 입력 받은 후 계산
        public PascalWorker(int rows) {
            this.rows = rows;
        }

        //
        @Override
        public Integer doInBackground() {
            int sum = 0;
            int[][] triangle = new int[rows][rows];
            // 기본 파스칼 삼각형 계산하기
            for (int i = 0; i < rows; i++) {
                triangle[i][0] = 1;
                triangle[i][i] = 1;
                for (int j = 1; j < i; j++) {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                }
                StringBuilder row = new StringBuilder();
                for (int j = 0; j <= i; j++) {
                    if (isCancelled()) return sum;
                    row.append(triangle[i][j]).append(" ");
                    sum += triangle[i][j];
                }
                publish(new Object[]{row.toString(), (i + 1) / (double) rows * 100, sum});
                try {
                    // 천천히 파스칼 삼각형을 출력하도록 sleep 설정
                    Thread.sleep(300);
                } catch (InterruptedException e) {
                    if (isCancelled()) return sum;
                }
            }
            return sum;
        }
        
        // 중간결과 처리
        @Override
        public void process(List<Object[]> chunks) {
            for (Object[] chunk : chunks) {
                // 삼각형의 한 행 한 행을 텍스트 area 영역에 추가
                textArea.append((String) chunk[0] + "\n");
                // 진행 상황을 출력
                progressBar.setValue((int) Math.round((double) chunk[1]));
                // 현재까지의 중간 sum 값을 출력
                sumLabel.setText("Sum =  " + chunk[2]);
            }
        }

        @Override
        public void done() {
            try {
                int sum = get();
                sumLabel.setText("Sum =  " + sum);
                // bar의 값은 최종 100.
                progressBar.setValue(100);


            } // 에러가 발생하면 에러 출력.
            catch (InterruptedException | ExecutionException e) {
                JOptionPane.showMessageDialog(PascalTriangle.this,
                        "Error ",
                        "Error", JOptionPane.ERROR_MESSAGE);


            } // 작업취소 시 그저 멈춤. 이것이 없다면 cancel시 에러 발생
            catch (CancellationException e) {
            }

            // 모든 활동이 끝나면 다시 버튼 활성화
            actionButton.setEnabled(true);
            cancelButton.setEnabled(false);
        }
    }


    public static void main(String[] args) {
        SwingUtilities.invokeLater(PascalTriangle::new);
    }
}