/**
 * 「Javaプログラミング」演習03-03
 * @author : Cyber Java
 */
public class Exer03_03 {
    /*
     * メインメソッド
     */
    public static void main(String[] args) {
        // String型変数お腹の状態を宣言する
        String 変数お腹の状態; 
        // boolean変数ダイエット中を宣言
        boolean 変数ダイエット中;    
        // 変数お腹の状態に適切な値を代入
        変数お腹の状態 = "空腹";
        // 変数ダイエット中に適切な値を代入
        変数ダイエット中 = false;
        // お腹の状態をが「空腹」かどうかを確認
        if(変数お腹の状態 == "空腹") {
            // ダイエット状態を確認
            if(変数ダイエット中 == true) {
                // ダイエット状態が「true」の場合は、「低カロリーのものを食べる」を出力
                System.out.println("低カロリーのものを食べる");    
            } else {
                // ダイエット状態が「false」の場合は、「好きなお菓子を食べる」を出力
                System.out.println("好きなお菓子を食べる");    
            }
        } else {
            // お腹の状態が「空腹」ではない場合は、「勉強を続ける」を出力
            System.out.println("勉強を続ける");
        }
    }
}