import java.util.LinkedHashSet;
import java.util.Iterator;
import java.util.Set;

public class LinkedHashSetExample {
    public static void main(String[] args) {
        Set<String> obj1 = new LinkedHashSet<String>();

        obj1.add("India");

        obj1.add("USA");

        obj1.add("Russia");

        obj1.add("China");

        // System.out.println(obj1);

        Iterator<String> itr = obj1.iterator();

        while(itr.hasNext())
        {
            if(obj1.equals("China"))
            {
                obj1.remove("China");
            }

            System.out.print(itr.next() + " ");
        }
    }
}
