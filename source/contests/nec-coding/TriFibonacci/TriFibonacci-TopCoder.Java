public class TriFibonacci
{
  public int complete(int[] A)
  {
    int i, x=-1, t;
    
    for(i=0; i<A.length; i++)
    {
      if(A[i] == -1)
      {
        x = i;
        break;
      }
    }
    
    if(x == -1)
      return -1;
      
    if(x < 3)
    {
      for(i=0, t=0; i<3; i++)
        t += A[i];
      t += 1;
      A[x] = A[3]-t;
    }
    else
      A[x] = A[x-1]+A[x-2]+A[x-3];
    
    if(A[x] <= 0)
      return -1;
    
    for(i=3; i<A.length; i++)
    {
      if(A[i] != A[i-1]+A[i-2]+A[i-3])
        return -1;
    }
    
    return A[x];
  }
}
