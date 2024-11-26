import java.util.HashSet;
import java.util.Set;

public class DuplicateElement
{
    public static void main(String[] args) {
        Set<String> unique = new HashSet<String>();

        Set<String> dupli = new HashSet<String>();


        for(String a : args)
        {
            if(!unique.add(a))
            {
                dupli.add(a);
            }

            unique.removeAll(dupli);
        }

        System.out.println("Unique Words: " + unique);

        System.out.println("Duplicate Words: " + dupli);

    }
}