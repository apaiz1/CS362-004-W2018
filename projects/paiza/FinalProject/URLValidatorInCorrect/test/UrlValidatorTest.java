

import junit.framework.TestCase;

import java.util.concurrent.ThreadLocalRandom;

// Adam Paiz
// Thomas Buteau
// Jacob Skinner
// CS 362
// Final Project Part B
// 2018-03-





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
    //You can use this function to implement your manual testing
       UrlValidator urlChecker = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES );

       assertTrue(urlChecker.isValid("http://www.oregonstate.edu"));
       assertTrue(urlChecker.isValid("http://www.oregonstate.edu/future"));
       assertTrue(urlChecker.isValid("http://www.oregonstate.edu/"));
       assertTrue(urlChecker.isValid("http://oregonstate.edu"));
       assertTrue(urlChecker.isValid("http://oregonstate.edu?key=value"));
       assertTrue(urlChecker.isValid("http://adam.oregonstate.edu"));
       assertTrue(urlChecker.isValid("http://oregonstate.io"));
       assertTrue(urlChecker.isValid("http://oregonstate.es"));
       assertTrue(urlChecker.isValid("http://localhost"));
       assertTrue(urlChecker.isValid("http://localhost/"));
       System.out.println(urlChecker.isValid("http://www.oregonstate.edu/departments/biology"));
       /*
       assertTrue(urlChecker.isValid("https://www.oregonstate.edu"));
       assertTrue(urlChecker.isValid("https://www.oregonstate.edu/future"));

       assertTrue(urlChecker.isValid("https://www.oregonstate.edu/"));
       assertTrue(urlChecker.isValid("https://oregonstate.edu"));
       assertTrue(urlChecker.isValid("https://oregonstate.io"));
       assertTrue(urlChecker.isValid("https://localhost"));
       assertTrue(urlChecker.isValid("https://localhost/"));

       assertTrue(urlChecker.isValid("http://www.oregonstate.edu/future/"));
       assertTrue(urlChecker.isValid("http://www.oregonstate.edu/future/time"));
       assertTrue(urlChecker.isValid("http://www.oregonstate.edu/"));
*/
       /*
       assertFalse(urlChecker.isValid("h3://www.oregonstate.edu/"));
       assertFalse(urlChecker.isValid("h3://www.oregonstate.edu/future"));
       assertFalse(urlChecker.isValid("h3://www.oregonstate.edu/future/"));
       assertFalse(urlChecker.isValid("h3://www.oregonstate.edu/future/time"));
       */

   }
    //Function to generate random number taken from
    // https://stackoverflow.com/questions/363681/how-do-i-generate-random-integers-within-a-specific-range-in-java
    public static int rand(int min, int max) {
        int num = ThreadLocalRandom.current().nextInt(min, max+1);
        return num;
    }


    public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   
       //This partition tests known good scheme and ports against a mix of valid and invalid authorities
       UrlValidator urlVal = new UrlValidator(null, null, 1);
       System.out.print("Starting first partition test.\n");

       String[] scheme_good = {"http://", "ftp://", "https://"};
       String[] authority_valid = {"www.google.com", "www.oregonstate.edu", "www.stackoverflow.com"};
       String[] authority_invalid = {"wtf.google.fail", "p2w.lootboxes.bad", "HanShotFirst.Disney.gov"};
       String[] port_valid = {":80", ":443"};
       int failed_tests = 0;
       for(int i = 0; i < 10; i++) {
           if (i % 2 == 0) { //even
               String test = scheme_good[rand(0, 2)] + authority_valid[rand(0, 2)] + port_valid[rand(0, 1)];
               System.out.print("Testing: " + test + " Should pass.\n");
               if (urlVal.isValid(test)) {
                   System.out.print(" Passed\n\n");
               } else {
                   System.out.print(" Failed\n\n");
                   failed_tests++;
               }
           } else {
               String test = scheme_good[rand(0, 2)] + authority_invalid[rand(0, 2)] + port_valid[rand(0, 1)];
               System.out.print("Testing: " + test + " Should fail.\n");
               if (urlVal.isValid(test)) {
                   System.out.print(" Passed\n\n");
                   failed_tests++; //Expected outcome is a failed test so this is an error to report
               } else {
                   System.out.print(" Failed\n\n");
               }
           }
       }
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }

   public static void main(){
       UrlValidatorTest ourTest = new UrlValidatorTest("group tests");
       ourTest.testManualTest();
   }


}
