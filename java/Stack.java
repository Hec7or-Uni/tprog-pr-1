import java.lang.Iterable;
import java.util.Iterator;

interface Stack<T> extends Iterable<T> {
    public boolean push(T t);
    public boolean pop();
    public Iterator<T> iterator();
}