import java.util.Scanner;

public class Exer02_02 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("x+y = ?");
        System.out.println("xを入力ください（整数のみ）");

        int x_int = in.nextInt();
        
        System.out.println("yを入力してください（整数のみ）");
        int y_int = in.nextInt();
        
        System.out.println("x + y = "+ (x_int + y_int));

        in.close();
    }
}