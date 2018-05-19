import java.util.Scanner; 
import java.math.BigInteger; 

class Main {
    public static BigInteger fact(int n){
        if(n==0) return BigInteger.ONE;
        BigInteger ans = new BigInteger(Integer.toString(n));
        n--;
        while(n!=0){
        ans = ans.multiply(new BigInteger(Integer.toString(n)));
        n--;
        }
        return ans;
    } 
    public static BigInteger solve(int n){
        BigInteger ans = fact(2*n);
        BigInteger nfac = fact(n);
        ans = ans.divide(nfac);
        ans = ans.divide(new BigInteger(Integer.toString(n+1)));
        return ans;
        
    }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int caseNo = 1;
    int N = sc.nextInt();
    BigInteger[] factAr = new BigInteger[21];
    for(int i=0;i<=20;i++){
        factAr[i] = fact(i);
    }
    for(int j=1;j<=N;j++){
        String s = sc.next();
        int[] arr = new int[30];
        BigInteger b = factAr[s.length()];
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            arr[c-'A']++;
            b = b.divide(new BigInteger(Integer.toString(arr[c-'A'])));
        }
    
        System.out.println("Data set "+j+": "+b.toString());
    }
    
    } 
}                       
