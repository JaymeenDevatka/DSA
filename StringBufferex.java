public class StringBufferex
{
    public static void main(String[] args) {
        String s1 = "Jaymeen";

        String s2 = "Jaymeen";

        StringBuffer s3 = new StringBuffer("jaymeen");

        StringBuffer s4 = new StringBuffer("jaymeen");


        System.out.println(s1.equals(s2));

        System.out.println(s3.equals(s4));
    }
}