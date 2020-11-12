# Cloning the CodeLab Repository - Visual Studio

This guide will detail how to clone this repository to your local machine using GitHub desktop.

[Click here to view a video guide](https://www.loom.com/share/6e89edadb5484d09bf2edf37bea36475)

&nbsp;
&nbsp;

## Step 1

So far we have successfully created your repository on GitHub, but we need to download this to your machine so you can write your code and then send this back to GitHub. For this we will use GitHub desktop.

Open GitHub desktop and clone the repository. If you have no existing repositories you can do this by clicking the ```Clone a Repository``` button on the opening screen. If you already have some repositories downloaded you can add another on by selecting ```File --> Clone Repository``` from the menu bar.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/get-started-screen.png">
</p>

&nbsp;
&nbsp;

## Step 2

You will be presented with *Clone a Repository*  screen similar to the one below. You should look for the repository you wish to clone from those listed. This will be named something like: CodeLab-II-20-21/codelab-ii-yourgithubusername

Click ```Choose...```next to the local path field and browse to sensible location on your machine to save the repository, eg: ```Documents → Dev```.

Once you have selected a folder on your machine click ```Clone``` to download the repository.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/clone-repo.png">
</p>

&nbsp;
&nbsp;

## Step 3

You should now have a copy of the repository from Github on your local machine and GitHub desktop should look like the below screen. You are now ready to add code to your repository and undertake the coding challenges. The remaining steps in this guide demo how to create a project in the repository.


<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/cloned.png">
</p>

&nbsp;
&nbsp;

## Step 4

Select ```Create a new project``` from the startup screen (or ```File → New Project``` if already in Visual Studio).

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/getting-started-vs.png">
</p>

&nbsp;
&nbsp;

## Step 5

Select ```Empty Project``` from the templates and click ```next```.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/empty-project.png">
</p>

&nbsp;
&nbsp;

## Step 6

Configure your project settings:

* In the ```Project Name``` box provide a name for the project (e.g: HelloWorld)
* In the ```Location``` box browse to the location where you want to save your project (e.g. the exercises folder in the relevant chapter of your repository).

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/configure-project.png">
</p>

*If you are taking option 2 of the Programming Skills Portfolio Assessment you should create a new folder in the root of the repository for the exercises and name these appropriately (e.g. "Football Draw")*

&nbsp;
&nbsp;

## Step 7

You will be presented with the following screen (Solution Explorer may appear on the left or the right).

* In the solution explorer right click the ```Source Files``` folder
* Click ```Add → New Item``` from the popup menu that appears

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/add-new.png">
</p>

&nbsp;
&nbsp;

## Step 8

Add a new C++ (```.cpp```) file and name it ```main.cpp```. Click ```Add```.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/main.png">
</p>

&nbsp;
&nbsp;

## Step 9

Your main.cpp file will initially be blank. Add the following 'skeleton' code ready to create the rest of your program.

```C++
#include <iostream>
using namespace std;

int main(){


  return 0;
}
```

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/vs-project.png">
</p>

&nbsp;
&nbsp;

## Step 10

Once you have completed your program you can commit the solution to your repository and push it back to GitHub. Github Desktop will keep track of your changes in your main.cpp file and any other files you add to your project. You should regularly make commits to ensure you can fall back to previous versions if things go wrong. You should also push your commits back up to your Github repository often, this will make sure you have a backup of your work.

In GitHub desktop write a commit message for the changes made (e.g. *Completed Hello World Program*) and click ```commit to master```

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/commit.png">
</p>

&nbsp;
&nbsp;

## Step 11

Once you have commited the changes you need to push them back to GitHub to keep your local and remote repositories in sync. To do so click ```Push Origin```

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/push-origina.png">
</p>

&nbsp;
&nbsp;

## Step 12

Your code should now also be backed up on GitHub. If you want to check or need to view your repository on GitHub you can do so at anytime by clicking the ```View on GitHub``` button in GitHub desktop.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/view-on-github.png">
</p>

&nbsp;
&nbsp;

## Step 13

You should be able to find the exercise you pushed by navigating to the relevant exercises folder on your GitHub repository....

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/on-github.png">
</p>

