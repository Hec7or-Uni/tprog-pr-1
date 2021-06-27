// Similar a los includes de C++, importamos aquellas clases que nos sean utiles
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.lang.UnsupportedOperationException;

public class StaticStack<T> implements Stack<T> {
	private static final int MAX = 40;
	private T[] datos;
	private int total;

	@SuppressWarnings("unchecked")
	public StaticStack() {
		datos = (T[])(new Object[MAX]);
		total = 0;
	}

	public boolean push(T t) {
		boolean sePuede = total < MAX;
		if  (sePuede) {
			datos[total] = t;
			total++;
		}

		return sePuede;
	}

	public boolean pop() {
		boolean sePuede = total > 0;
		if (sePuede) total--;

		return sePuede;
	}

	private class StackIterator implements Iterator<T> {
		StaticStack<T> stk;
		int i;

		private StackIterator(StaticStack<T> stk) {
			this.stk = stk;
			i        = stk.total - 1;
		}

		public boolean hasNext() {
			return i >= 0;
		}

		public T next() throws NoSuchElementException {
			if (!hasNext()) {
				throw new NoSuchElementException();
			} else {
				return stk.datos[i--];
			}
		}

		public void remove() throws UnsupportedOperationException {
			throw new UnsupportedOperationException();
		}
	}

	public Iterator<T> iterator() {
		return new StackIterator(this);
	}
}
