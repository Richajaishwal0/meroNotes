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
```java
package org.example;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String [] args) throws InterruptedException {
    System.setProperty("webdriver.chrome.driver","D:\\chrome-selenium-driver\\chromedriver.exe");

   //to open chrome browser
    WebDriver driver= new ChromeDriver();

    //link to the website to be opened
    driver.get("https://www.amazon.com");

    WebElement contin=driver.findElement(By.className("a-button-text"));
    contin.click();

    WebElement gm= driver.findElement(By.id("twotabsearchtextbox"));
    gm.sendKeys("chocolates");

    WebElement  name =driver.findElement(By.id("nav-search-submit-button"));
    name.click();

    WebElement  item =driver.findElement(By.className("s-image"));
    item.click();

//    link text
//    WebElement add=driver.findElement(By.linkText("Add to List"));
//    add.click();

    //partial link text
    WebElement parlink=driver.findElement(By.partialLinkText("Add to"));
    parlink.click();

//    WebElement login=driver.findElement(By.name("login"));
//    login.click();

// xpath
//        absolute -- using attribute  //*[@id="ap_email_login"]
//        relative -- based on position /html/body/div[1]/div[1]/div[2]/div/div/div/div/span/form/span/span/input
     WebElement gmail_login=driver.findElement(By.xpath("//*[@id=\"ap_email_login\"]"));
     gmail_login.sendKeys("2023richajaiswal@gmail.com");

     WebElement conti=driver.findElement(By.xpath("/html/body/div[1]/div[1]/div[2]/div/div/div/div/span/form/span/span/input"));
     conti.click();
    }
}

```

## WebDriver Methods
```
String var=driver.getCurrentUrl();
System.out.println(var);

String title=driver.getTitle();
System.out.println(title);

element.getText() -> to fetch inner text of element
WebElement element= driver.findElement(By.xpath("anylink"));
String linkText=element.getText();


element.getTagName();
WebElement element=driver.findElement(By.id("submit"));
String TagName=element.getTagName();

To get css property value
WebElement contin=driver.findElement(By.className("a-button-text"));
String css=contin.getCssValue("color");
String attribute=contin.getAttribute("class"); //get attribute
contin.click();

System.out.println(attribute);
System.out.println(css);

element.submit() // to submit form

String variable = driver.getPageSource()
driver.quit() //closes all the browsers --everywindow
driver.close()  //closes avtiver browser


//no attributes for navigation so we have methods

        driver.navigate().to("https://www.flipkart.com/");
        Thread.sleep(3000);
        driver.navigate().back(); //goes back to amazon
        Thread.sleep(3000);
        //moves single time forward in the browser
        driver.navigate().forward(); //goes back to flipkart
        //refresh the current webpage
        driver.navigate().refresh();
<img width="162" height="72" alt="image" src="https://github.com/user-attachments/assets/dcced74c-970a-47b8-97f5-d81aa1a426bb" />


