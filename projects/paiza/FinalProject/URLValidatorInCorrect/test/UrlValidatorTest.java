

import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;

// Adam Paiz -paiza
// Thomas John Buteau - buteaut
// Jacob Skinner- skinnjac
// CS 362
// Final Project Part B
// 2018-03-19





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }


    public void miscTests()
    {
    // This function has random tests that did not fit in the other three groups.
        UrlValidator urlChecker = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES );
        String httpsTest = "http://www.google.com/hope/brave";
        try{
            if (urlChecker.isValid(httpsTest)) {
                System.out.print(" Passed\n\n");
            } else {
                System.out.print(" Failed\n\n");
            }
        }catch(IllegalArgumentException ex){
            System.out.println("\n Test: " + httpsTest + " Caused an IllegalArgumentException that was caught.");
            System.out.print("This test is Failed.\n");
            ex.printStackTrace();
        }catch(ExceptionInInitializerError ex){
            System.out.println("\n Test: " + httpsTest + " Caused an ExceptionInInitializerError that was caught.");
            System.out.print("This test is Failed.\n");
            ex.printStackTrace();
        }
        System.out.println(urlChecker.isValid("http://www.oregonstate.edu/departments/biology"));

    }
    public void checkUrl(UrlValidator urlChecker, String url, String expected)
    {
    //This function will use a standard check for a manual URL
        try {
            System.out.print("\nCheck of " + url + ".");
            if (urlChecker.isValid(url)) {
                System.out.print(" true. PASSED\n");
            } else {
                System.out.print(" false. FAILED\n");
                System.out.println("This failed so we did not use an assertion");
                System.out.println("This was "+ expected + ".");
            }
        }catch(IllegalArgumentException ex){
            System.out.println("\n Test: " + url + " Caused an IllegalArgumentException that was caught.");
            System.out.print("This test is Failed.\n");
            ex.printStackTrace();
        }catch(ExceptionInInitializerError ex){
            System.out.println("\n Test: " + url + " Caused an ExceptionInInitializerError that was caught.");
            System.out.print("This test is Failed.\n");
            ex.printStackTrace();
        }
    }
   public void testManualTest()
   {
   //Our manually written urls are checked here.
   //Note: many urls failed the assertion, so we used the helper function with them.
       System.out.println("*************************************************************");
       System.out.print("Starting manual testing\n");
       System.out.println("*************************************************************");
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
       assertTrue(urlChecker.isValid("http://www.github.com"));
       assertTrue(urlChecker.isValid("http://ww3.github.com"));
       assertTrue(urlChecker.isValid("http://ww3.github.codfgon"));
       checkUrl(urlChecker, "google.com", "not expected");
       checkUrl(urlChecker, "www.google.com", "not expected");
       checkUrl(urlChecker, "www.google.com", "not expected");
       checkUrl(urlChecker, "google.com:80","not expected");
       checkUrl(urlChecker, "www.google.com:80","not expected");
       assertTrue(urlChecker.isValid("http://www.google.co.uk"));
       checkUrl(urlChecker, "htpp://www.google.com:80","expected");
       assertTrue(urlChecker.isValid("http://www.url.com"));
       assertTrue(urlChecker.isValid("http://url.com"));
       checkUrl(urlChecker, "www.url.com","not expected");
       checkUrl(urlChecker, "url.com","not expected");
       assertTrue(urlChecker.isValid("http://www.url.com/"));
       assertTrue(urlChecker.isValid("http://www.url.com/example"));
       checkUrl(urlChecker, "http://www.url.com:port","expected");
       assertTrue(urlChecker.isValid("http://url"));
       assertTrue(urlChecker.isValid("http://www.url.nothing"));
       assertTrue(urlChecker.isValid("http://www.url"));

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
   //The beginning of this section was written by Thomas.
   //Adam added the exceptions.
   UrlValidator urlVal = new UrlValidator(null, null, 1);
   System.out.println("*************************************************************");
   System.out.print("Starting first partition test.\n");
   System.out.println("*************************************************************");

   String[] scheme_good = {"http://", "ftp://", "https://"};
   String[] authority_valid = {"www.google.com", "www.oregonstate.edu", "www.stackoverflow.com"};
   String[] authority_invalid = {"wtf.google.fail", "p2w.lootboxes.bad", "HanShotFirst.Disney.gov"};
   String[] port_valid = {":80", ":443"};
   int failed_tests = 0;
   for(int i = 0; i < 10; i++) {
       if (i % 2 == 0) { //even
           String test = scheme_good[rand(0, 2)] + authority_valid[rand(0, 2)] + port_valid[rand(0, 1)];
           System.out.print("Testing: " + test + " Should pass.\n");
           try{
               if (urlVal.isValid(test)) {
                   System.out.print(" Passed\n\n");
               } else {
                   System.out.print(" Failed\n\n");
                   failed_tests++;
               }
           } catch(IllegalArgumentException ex) {
               System.out.println("\n Test: " + test + " Caused an IllegalArgumentException that was caught.");
               System.out.print("This test is Failed.\n");
           } catch(ExceptionInInitializerError ex) {
               System.out.println("\n Test: " + test + " Caused an ExceptionInInitializerError that was caught.");
               System.out.print("This test is Failed.\n");
           } catch(NoClassDefFoundError ex){
               System.out.println("\n Test: " + test + " Caused an NoClassDefFoundError that was caught.");
               System.out.print("This test is Failed.\n");
           }

       } else {
           String test = scheme_good[rand(0, 2)] + authority_invalid[rand(0, 2)] + port_valid[rand(0, 1)];
           System.out.print("Testing: " + test + " Should fail.\n");
           try{
               if (urlVal.isValid(test)) {
                   System.out.print(" Passed\n\n");
                   failed_tests++; //Expected outcome is a failed test so this is an error to report
               } else {
                   System.out.print(" Failed\n\n");
               }
           }catch(IllegalArgumentException ex){
               System.out.println("\n Test: " + test + " Caused an IllegalArgumentException that was caught.");
               System.out.print("This test is Failed.\n");
           }catch(ExceptionInInitializerError ex){
               System.out.println("\n Test: " + test + " Caused an ExceptionInInitializerError that was caught.");
               System.out.print("This test is Failed.\n");
           }catch(NoClassDefFoundError ex){
               System.out.println("\n Test: " + test + " Caused an NoClassDefFoundError that was caught.");
               System.out.print("This test is Failed.\n");
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
       System.out.println("*************************************************************");
       System.out.println("Starting Programmatic Testing");
       System.out.println("*************************************************************");
       UrlValidator urlVal = new UrlValidator(null,null,1);
       String[] schemes = {"http://", "ftp://", "http://",""};
       String[] authority = {"www.google.com", "www.oregonstate.edu","google.com","oregonstate.edu"};
       String[] port = {":80",":443",""};
       String[] path = {"", "/one","/one/two"};
       int failedTests = 0;
       int passedTests = 0;
       ArrayList<String> failedUrls = new ArrayList<String>();
       ArrayList<String> failedUrlException = new ArrayList<String>();
       for(int i = 0; i< 1000; i++){
           String test = schemes[rand(0,3)] + authority[rand(0,2)] + port[rand(0,2)] +path[rand(0,2)];
           try{
               if (urlVal.isValid(test)){
                    passedTests += 1;
               }else{
                   failedTests += 1;
                   failedUrls.add(test);
               }
           } catch(IllegalArgumentException ex) {
                   failedTests += 1;
                   failedUrlException.add(test);
           } catch(ExceptionInInitializerError ex) {
                       failedTests += 1;
                       failedUrlException.add(test);
           } catch(NoClassDefFoundError ex){
                       failedTests += 1;
                       failedUrlException.add(test);
           }
       }
       System.out.println("Passing urls: "+ Integer.toString(passedTests) + ".");
       System.out.println("Failed urls: "+ Integer.toString(failedTests) + ".");
       System.out.println("Urls that failed and did not causes exceptions:");
       for(String name : failedUrls){
           System.out.println(name);
       }
       System.out.println("Urls that failed and caused an exception:");
       for(String name : failedUrlException){
           System.out.println(name);
       }

       System.out.println("Tests Complete");
       System.out.println("*************************************************************");

   }


   public static void main(){
       UrlValidatorTest ourTest = new UrlValidatorTest("group tests");
       ourTest.testManualTest();
   }


}
