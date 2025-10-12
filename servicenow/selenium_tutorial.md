```java
package org.example;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class Main {
    public static void main(String [] args) throws InterruptedException {
    System.setProperty("webdriver.chrome.driver","D:\\chrome-selenium-driver\\chromedriver.exe");
   //to open chrome browser
    WebDriver driver= new ChromeDriver();
    //link to the website to be opened ----launch application
    driver.get("https://www.gmail.com");
    //test the website
    String et=driver.getTitle();
    String title="gmail";
    if (et.equalsIgnoreCase(title))
    {
        System.out.println("test case passed");
    }
    else{
        System.out.println("failed");
    }
    Thread.sleep(3000); // wait for few seconds
    driver.close(); //close parent window
        //driver.quit() close parent and child window
    }
}

```
