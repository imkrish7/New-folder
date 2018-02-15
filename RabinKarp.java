import java.util.*;

class RabinKarp{
	
	static void search(String t,String p)
	{
		int n=t.length();
		int m=p.length();

		int sump=0;
		int sumt=0;

		for(int i=0;i<m;i++)
		{
		 sumt+=t.charAt(i);
		 sump+=p.charAt(i);
		}

		for(int i=m;i<n;i++)
		{
			if(sumt==sump)
			{
				System.out.println("Pattern found at"+ (i-m));
				
			}
			sumt-=t.charAt(i-m);
			sumt+=t.charAt(m);
			System.out.println(sumt+"-->"+sump);
		}

	}
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);

		String text=sc.nextLine();
		String pat=sc.next();

		search(text,pat);
	}
}