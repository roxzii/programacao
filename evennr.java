class MyEvenNumbers
{
   public static void main(String args[])
   {
      int num = 1;
      while(num<=100){
          if(num % 2 == 0)
             System.out.println("The number " + num + " is even");
          num = num + 1;
      }
   }
}
