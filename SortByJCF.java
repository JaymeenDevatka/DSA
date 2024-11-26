import java.util.Arrays;

public class SortByJCF {
    public static void main(String[] args) {
        int array[] = new int[10];

        // Populating the array
        for (int i = 0; i < 10; i++) {
            array[i] = -3 * i;
        }

        // Displaying the original array
        System.out.println("Original Array:");
        System.out.println(Arrays.toString(array));

        // Sorting the array using Arrays.sort()
        Arrays.sort(array);

        // Displaying the sorted array
        System.out.println("Sorted Array:");
        System.out.println(Arrays.toString(array));
    }
}
