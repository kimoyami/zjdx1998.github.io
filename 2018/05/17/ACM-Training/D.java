import java.util.Scanner;

public class D {
	private static Point[] p;
	private static int n;

	private static void Read() {
		Scanner cin = new Scanner(System.in);
		n = cin.nextInt();
		p = new Point[n+1];
		for(int i=1;i<=n;i++) {
			p[i] = new Point();
			p[i].x = cin.nextInt();
			p[i].y = cin.nextInt();
		}
		cin.close();
	}
	private	static boolean coline(Point A,Point B,Point C) {
		return (long)(B.y-A.y)*(C.x-A.x)==(long)(C.y-A.y)*(B.x-A.x);
	}
	private static boolean Check(Point A,Point B) {
		Point[] another = new Point[n+1];
		int CntColine=0;
		for(Point P : p) 
			if(P!=null && (!coline(A,B,P))) {
				another[++CntColine] = new Point();
				another[CntColine] = P;
			}
		for(int i=3;i<=CntColine;i++)
			if(!coline(another[i-2],another[i-1],another[i])) return false;
		return true;
	}
	public static void main(String[] args) {
		Read();
		if(n<=4) {
			System.out.println("YES");
			return;
		}
		if(Check(p[1],p[2])||Check(p[1],p[3])||Check(p[2],p[3])) {
			System.out.println("YES");
			return;
		}
		System.out.println("NO");
	}
}
class Point{
	int x,y;
	Point(){
		x = y = 0;
	}
}