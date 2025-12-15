import java.util.Scanner;
/**
* 「Java プログラミン」第 6 回レポート
* 課題 1：クラスメソッドを利用する
* 課題 2：条件分岐を利用する
* 課題 3：繰り返し処理を利用する
*
* @author Cyber Java
*/
public class Report06 {
public static void main(String[] args) {
// キーボードを読み取るクラスを宣言
Scanner scan = new Scanner(System.in);
// 繰り返し処理の条件を格納する変数を宣言して初期化。1:繰り返し処理を実行
String opt = "1";
// opt=1:繰り返し処理を実行
while (opt.equals("1")) {
// 入力範囲の説明
    System.out.println("四則演算を開始：1; 終了：任意キーを押してください。");
    // 入力値を繰り返し処理の条件変数に代入
    opt = scan.nextLine();
    // 入力値が 1 ではない場合は、繰り返し処理を中断
    if (!opt.equals("1"))
        break;

    // 引数を格納する配列変数を String 型に宣言しサイズを 3 に指定
    String[] parameters = new String[3];
    // 入力範囲の説明
    System.out.println("整数のオペランド 1 を入力してください。");
    // 整数のオペランド 1 の入力を引数に代入
    parameters[0] = scan.nextLine();
    // 引数 1 が数値かどうかをチェック
    boolean isNumeric = parameters[0].matches("[+-]?\\d*(\\.\\d+)?");
    if (!isNumeric) {
        // 引数 1 が数値ではない場合は、繰り返し処理をスキップ
        System.out.println("入力された整数のオペランド 1 は数値ではありません。");
        continue;
    }
    // 入力範囲の説明
    System.out.println("四則演算子を入力してください。");
    // 演算子の入力を引数 2 に代入
    parameters[1] = scan.nextLine();
    // 説明範囲の説明
    System.out.println("整数のオペランド 2 を入力してください。");
    // 整数のオペランド 2 の入力を引数に代入
    parameters[2] = scan.nextLine();
    // 引数 2 が数値かどうかをチェック
    isNumeric = parameters[2].matches("[+-]?\\d*(\\.\\d+)?");
    if (!isNumeric) {
    // 引数 2 が数値ではない場合は、繰り返し処理をスキップ
        System.out.println("入力された整数のオペランド 2 は数値ではありません。");
        continue;
    }
    // 四則演算用クラスメソッドを呼び出して、戻り値を受け取る
    String rst = calculate(parameters);
    // 戻り値が数値かどうかをチェック
    isNumeric = rst.matches("[+-]?\\d*(\\.\\d+)?");
    if (isNumeric) {
    // 戻り値が数値である場合は、ループで計算結果を出力
        for (int i = 0; i < parameters.length; i++) {
            System.out.print(parameters[i]+" ");
        }
        System.out.print("= ");

    }
    // そうではない場合は、例外メッセージを出力
    System.out.println(rst);
 }
 // プログラムを終了するメッセージを出力
    System.out.println("四則演算は終了・・・");
 }

static String calculate(String[] vals) {
// 戻り値を格納する変数の宣言と初期化
String rst ="予期せぬ出来事が起こりました。";
// 計算用 double 型の変数 x, y を宣言
double x, y;
// 計算の一時結果を格納する変数の宣言と初期化
double tmp = Double.NaN;
// 演算子の宣言
String opt;
// 引数 1 を受け取る
String x_str = vals[0];
// 引数 2 を受け取る
opt = vals[1];
// 引数 3 を受け取る
String y_str = vals[2];
// 引数 1 を double 型に変換
x = Double.valueOf(x_str);
// 引数 3 を double 型に変換
y = Double.valueOf(y_str);
// 計算を行う
switch (opt) {
    case "+":
        // 足し算の場合
        tmp = x + y;
        break;
    case "-":
        tmp = x - y;
        break;
    case "*":
        tmp = x * y;
        break;
    case "/":
        // 割り算の場合
        if (y != 0) {
        // 除数が 0 ではない場合
        tmp = x / y;
        } else {
        // 除数が 0 である場合
        rst = "0 で割ることはできません。";
        }
        break;
    default:
        // 演算子が四則演算子ではない場合
        rst = opt + "は無効な演算子です。";
    }
    if (!Double.isNaN(tmp)) {
    // 処理結果を String 型に変換
        rst = Double.valueOf(tmp).toString();
    }
        return rst;
}
}