# Creating a Project from Existing Code - Visual Studio

This guide outlines the steps for creating a project from existing code. This might be useful if you have submitted some code to GitHub and want to continue working on the code from a different computer. You will need these steps as the project solution files are ignored by GitHub desktop and only the code files are submitted. The steps below will allow you to regenerate the required project files on a different computer and run your existing code.

&nbsp;
&nbsp;

## Step 1

On the Visual Studio 2019 start up screen click “Continue without code”.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/without-code.png">
</p>

&nbsp;
&nbsp;

## Step 2

From the menubar select ```File →  New → Project from Existing Code```

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/existing-code.png">
</p>

&nbsp;
&nbsp;

## Step 3

In the wizard pop-up ensure project you would like to create is set as ```Visual C++``` & click ```Next```

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/wizard.png">
</p>

&nbsp;
&nbsp;

## Step 4

Click ```Browse``` to set the ```Project File Location``` and locate the folder containing the existing project (e.g. usb-shopper)

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/usb-shopper-vs.png">
</p>

&nbsp;
&nbsp;

## Step 5

In the ```Project Name``` field give the project a name that matches the existing one (e.g. usb-shopper). Click ```Next```

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/project-name.png">
</p>

&nbsp;
&nbsp;

## Step 6

Under "How do you want to build the project":
* Make sure ```Use Visual Studio``` is selected
* Set project type to ```Console application project```
* Click ```Finish```

You should now have the project files required to run your code.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/console.png">
</p>

