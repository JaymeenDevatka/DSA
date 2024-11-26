import java.util.*;

public class HashSetExam {
    public static void main(String[] args) {

        Set<Integer> set = new HashSet<>();

        set.add(1);
        set.add(2);
        set.add(3);

        Iterator<Integer> itr = set.iterator();

        while (itr.hasNext()) {
            System.out.print(itr.next() + " ");
        }

        // System.out.println(set);
    }
}