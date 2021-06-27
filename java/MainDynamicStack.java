import java.util.Iterator;

public class MainDynamicStack {
	public static void main(String[] args) {
		DynamicStack<Integer> ss = new DynamicStack<Integer>();

		ss.push(42);
		ss.push(15);
		ss.pop();
		for (int i = 0; i < 100; i+=5)
			ss.push(i);

		Iterator<Integer> iter = ss.iterator();
		while(iter.hasNext())
			System.out.print(iter.next()+" ");
		System.out.println();

		for (Integer i : ss)
			System.out.print(i+" ");
		System.out.println();
	}
}
