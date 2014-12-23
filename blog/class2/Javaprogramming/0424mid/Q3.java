package exam.q3.pack;

public class Q3 {
	public static void main(String[] args) {
		int a = 5;
		int b = 0;
		try{
			System.out.println(a/b);
		}catch(ArithmeticException e){
			e.printStackTrace();
		}catch(Exception e1){
			e1.printStackTrace();
		}
	}
}
