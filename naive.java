import java.util.*;

class naive{
	
	static void findpatter(String t,String p)
	{

	int n=t.length();
	int n2=p.length();

	for(int i=0;i<=n-n2;i++)
	{
		int j;
		for(j=0;j<n2;j++)
		{
		  if(t.charAt(i+j)!= p.charAt(j))
		   break;
		}
		   if(j==n2)
		   	System.out.println("Pattern found at"+i);
		

	}
	}
	
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);

		String text=sc.next();

		String pat=sc.next();

		findpatter(text,pat);



	} 
}