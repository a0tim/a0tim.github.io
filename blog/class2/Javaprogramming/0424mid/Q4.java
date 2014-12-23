import java.util.ArrayList;
import java.util.List;

import javax.swing.*;

public class Q4 extends JFrame{
	static List BArr;
	static char Seat[] = {'A','B','C','D','E','F'};
	public static void main(String[] args) {
		new Q4();
	}
	public Q4(){
		setAlwaysOnTop(true);
		setBounds(100,50,650,400);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(null);
		setResizable(false);
		setTitle("貿貿翊翊學生點名系統");
		setVisible(true);
		
		BArr = new ArrayList<JButton>();
		for(int i=0;i<6;i++){
			for(int j=0;j<12;j++){
				JButton JB = new JButton((String.valueOf(Seat[i])+j));
				JB.setBounds(j+80,i+40,30,20);
				this.add(JB);
				BArr.add(JB);
			}
		}
	}
}
