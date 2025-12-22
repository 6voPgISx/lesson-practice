import java.util.Random;
import java.util.Scanner;

/**
 * 「Java プログラミング」第 8 回レポート
 * すごろく：レースゲーム
 */


public class SugorokuRaceGame {
    // マスの最大値
    static int maxMass = 21;

    public static void main(String[] args) {
        // scanner を宣言してインスタンスを作成
        Scanner scanner = new Scanner(System.in);
        // random を宣言してインスタンスを作成
        Random random = new Random();
        // ウェルカムメッセージ
        System.out.println("すごろくゲームへようこそ!");
        System.out.println("プレイヤーは最大 4 人まで参加できます。");
        // プレイ人数変数の初期化
        int numPlayers = 0;
        do {
            System.out.print("プレイヤーの人数（1 から 4 人まで）を入力してください: ");
            numPlayers = scanner.nextInt();
        } while (numPlayers < 1 || numPlayers > 4);

        
        // (1) Player 型の配列変数 players を宣言
        Player[] players = new Player[numPlayers];

        // (2) プレイヤーのインスタンスを生成
        for (int i = 0; i < numPlayers; i++) {
            players[i] = new Player();
            players[i].setPosition(0);
        }

        // バッファのクリア
        scanner.nextLine();

        // game over フラグ
        boolean isGameOver = false;
        int loop = 0;

        // (3) 初期位置を表示
        printMass(players);

        System.out.println("Enter キーを押してゲームを開始します。");
        scanner.nextLine();

        // ゲーム開始
        while (true) {
            loop++;
            System.out.println("************************ ループ " + loop + " ************************");

            for (int i = 0; i < numPlayers; i++) {
                // (4) すでにゴールしている場合はスキップ
                if (players[i].getPosition() >= (maxMass - 1)) {
                    continue;
                }

                System.out.println("----------- プレイヤー " + (i + 1) + " -----------");
                System.out.println("プレイヤー " + (i + 1) + " の番です。");
                System.out.print("Enter キーを押してサイコロを振ってください...");
                scanner.nextLine();

                int diceRoll = random.nextInt(6) + 1;

                // (5) 現在位置を取得
                int curPosition = players[i].getPosition();

                // (6) 新しい位置を設定
                players[i].setPosition(curPosition + diceRoll);

                System.out.println("サイコロの目: " + diceRoll);
                System.out.println("現在の位置: " + players[i].getPosition());

                printMass(players);

                if (players[i].getPosition() >= (maxMass - 1)) {
                    System.out.println("プレイヤー " + (i + 1) + " がゴールに到達しました!");
                }

                boolean allPlayersFinished = true;
                for (int j = 0; j < numPlayers; j++) {
                    if (players[j].getPosition() < (maxMass - 1)) {
                        allPlayersFinished = false;
                        break;
                    }
                }

                if (allPlayersFinished) {
                    System.out.println("ゲーム終了!");
                    scanner.close();
                    isGameOver = true;
                    break;
                }
            }

            // (7) Game Over 判定
            if (isGameOver) {
                break;
            }
        }
    }

    /**
     * プレイヤーの位置を出力
     */
    static void printMass(Player[] players) {
        // (8) players.length
        for (int i = 0; i < players.length; i++) {
            System.out.print("プレイヤー" + (i + 1) + "：");
            for (int j = 0; j < maxMass; j++) {
                if (j == players[i].getPosition()) {
                    System.out.print("●");
                } else {
                    System.out.print("□");
                }
            }
            System.out.println();
        }
    }
}

/**
 * プレイヤークラス
 */
class Player {
    private int position;

    public int getPosition() {
        return position;
    }

    public void setPosition(int position) {
        this.position = position;
    }
}