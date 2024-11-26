import java.util.Iterator;
import java.util.TreeSet;

public class TreeByJava {
    public static void main(String[] args) {
        
        TreeSet<Integer> t1 = new TreeSet<>();
        Iterator i = t1.iterator();
        t1.add(10);
        t1.add(20);
        t1.add(30);

        System.out.println(i.getClass());
    }
}