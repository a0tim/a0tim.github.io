package  exam.q2.pack;

public class Q2 {
	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		ThreadA a = new ThreadA("a", 1);
	}

}

class ThreadA extends Thread{
	String name;
	int no;
	
	ThreadA(String name, int no) throws InterruptedException{
		this.name = name;
		this.no = no;
		ThreadB b = new ThreadB("b", 1);
		this.start();
		this.yield();
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0;i<5000;i++){
			i=i;
		}
		System.out.println(this.name);
	}	
}

class ThreadB extends Thread{
	String name;
	int no;
	
	ThreadB(String name, int no) throws InterruptedException{
		this.name = name;
		this.no = no;
		this.start();
		this.join();
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0;i<5000;i++){
			i=i;
		}
		System.out.println(this.name);
	}	
}