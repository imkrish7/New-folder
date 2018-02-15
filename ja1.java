
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes
import java.util.*;


// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

class TestClass {
    public static void main(String args[] ) throws Exception {
      
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();                // Reading input from STDIN
       
        //Scanner
        Scanner s = new Scanner(System.in);
        //String name = s.nextLine(); 
        
    // Reading input from STDIN
    
    int R,C;
    R=s.nextInt();
    C=s.nextInt();
    
    int arr[][]=new int[R+1][C+1];
    
    for(int i=0;i<=R;i++)
    {
        for(int j=0;j<=C;j++)
        {
            if(j==0 || i==0)
               arr[i][j]=0;
               
            else
            {
                arr[i][j]=s.nextInt();
            }
        }
    }
    
    int dp[][]=new int[R+1][C+1];
    
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            dp[i][j]=dp[i][j-1]+arr[i][j];
        }
    }
    
    int q=s.nextInt();
    
    for(int i=0;i<q;i++)
    {
        int x1=s.nextInt();
        int y1=s.nextInt();
        int x2=s.nextInt();
        int y2=s.nextInt();
        int ans=0;
        
        for(int j=y1;j<=y2;j++)
        {
            ans+=dp[x2][j];
            
        }
        System.out.println(ans);
        
    }

    }
}
