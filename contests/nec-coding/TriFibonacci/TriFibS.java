import java.util.*;

class TriFibonacci
{
  public int complete(Vector<Integer> A)
  {
    int i, x=-1, t;
    
    for(i=0; i<A.size(); i++)
    {
      if(A.get(i) == -1)
      {
        x = i;
        break;
      }
    }
    
    if(x == -1) // -1 is not found.
      return -1; 
      
    if(x < 3)
    {
      for(i=0, t=0; i<3; i++)
        t += A.get(i);

      t += 1;
      A.set(x, A.get(3)-t);
    }
    else
	A.set(x,(A.get(x-1) + A.get(x-2) + A.get(x-3) ));

    if(A.get(x) <= 0)
      return -1;
    
    for(i=3; i<A.size(); i++)
    {
      if(A.get(i) != (A.get(i-1) + A.get(i-2) + A.get(i-3)))
        return -1;
    }
    
    return A.get(x);

  }
} 

class TriFiboSolution
{
	public static void main(String args[])
	{
		Vector<Integer> myVector = new Vector<Integer>();

		myVector.addElement(10);
		myVector.addElement(20);
		myVector.addElement(30);
		myVector.addElement(60);
		myVector.addElement(-1);
		myVector.addElement(200);

		int i;
		int ans;

		TriFibonacci obj = new TriFibonacci();
		ans = obj.complete(myVector);
		System.out.println(ans);

	}
}
