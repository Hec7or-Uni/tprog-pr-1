import java.util.Iterator;
import java.util.NoSuchElementException;
import java.lang.UnsupportedOperationException;

public class DynamicStack<T> implements Stack<T> {
	public Nodo<T> cima;

	private class Nodo<L> {
		private L dato;
		private Nodo<L> sig;

		public Nodo(L e, Nodo<L> sig) {
			this.dato = e;
			this.sig = sig;
		}
	}

	public DynamicStack() {
		cima = null;
	}

	public boolean push(T t) {
		Nodo<T> aux = new Nodo<T>(t, cima);
		cima = aux;
		return true;
	}

	public boolean pop() {
		if (cima == null) {
			return false;
		} else {
			Nodo<T> aux = cima.sig;
			cima = null;
			cima = aux;
			return true;
		}
	}

	private class StackIterator implements Iterator<T> {
		DynamicStack<T> stk;

		private StackIterator(DynamicStack<T> stk) {
			this.stk = stk;
		}

		public boolean hasNext() {
			return stk.cima != null;
		}

		public T next() throws NoSuchElementException {
			if (!hasNext()) {
				throw new NoSuchElementException();
			} else {
				T aux = stk.cima.dato;
				stk.cima = stk.cima.sig;
				return aux;
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
