import java.io.*;
import java.util.StringTokenizer;

public class Q1 {
	public static void main(String[] args) {
		File F = new File("C:\\Q1_1.txt");
		File F2 = new File("C:\\result1_1.txt");
		File F3 = new File("C:\\result1_2.txt");
		File F4 = new File("C:\\result1_3.txt");
		int count_word = 0;
		int count_mot = 0;
		String add_mot = "";
		String SS = "";
		String S_hwi = "";
		String S_aio = "";
		Boolean hasA = false;
		Boolean hasI = false;
		Boolean hasO = false;
		StringTokenizer STT;
		BufferedWriter BW;
		try {
			BufferedReader BR = new BufferedReader(new InputStreamReader(new FileInputStream(F)));
			F2.createNewFile();
			String S = BR.readLine();
			String S2 = S;
			for(int i=S.length()-1;i>=0;i--){
				S_hwi += S.charAt(i);
			}
			StringTokenizer ST = new StringTokenizer(S2);
			count_word = ST.countTokens();
			for(int i=0;i<S2.length();i++){
				if(S2.charAt(i)=='a'||S2.charAt(i)=='A'||S2.charAt(i)=='e'||S2.charAt(i)=='E'||S2.charAt(i)=='i'||S2.charAt(i)=='I'||S2.charAt(i)=='o'||S2.charAt(i)=='O'||S2.charAt(i)=='u'||S2.charAt(i)=='U'){
					count_mot++;
					add_mot += i+"\r\n";
				}
			}
			while(ST.hasMoreTokens()){
				SS = ST.nextToken();
				STT = new StringTokenizer(SS,",");
				SS = STT.nextToken();
				STT = new StringTokenizer(SS,".");
				SS = STT.nextToken();
				for(int i=0;i<SS.length();i++){
					if(SS.charAt(i)=='a'||SS.charAt(i)=='A'){
						hasA = true;
					}else if(SS.charAt(i)=='i'||SS.charAt(i)=='I'){
						hasI = true;
					}else if(SS.charAt(i)=='o'||SS.charAt(i)=='O'){
						hasO = true;
					}
				}
				if(hasA && hasI && hasO){
					S_aio += SS+"\r\n";
				}
				hasA = false;
				hasI = false;
				hasO = false;
			}
			
			BW = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(F2)));
			BW.write(S_hwi);
			BW.flush();
			BW = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(F3)));
			BW.write("共有"+count_word+"個單字,"+count_mot+"個母音\r\n同時含有aio的單字:"+S_aio);
			BW.flush();
			BW = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(F4)));
			BW.write("各母音出現的位置:"+add_mot);
			BW.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
