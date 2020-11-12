# Getting Started with Visual Studio

When downloading Visual Studio you should use the community edition which is free. Also make sure you install the desktop development with C++ workload when installing. This will ensure you have all the necessary components to code in C++.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/workloads.png">
</p>

&nbsp;
&nbsp;

[Click here to view a video guide](https://www.loom.com/share/142f6d1f8afe448ca6fab1771ff6a960)


## Step 1

Select ```Create a new project``` from the startup screen (or ```File → New Project``` if already in Visual Studio).

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/getting-started-vs.png">
</p>

&nbsp;
&nbsp;

## Step 2

Select ```Empty Project``` from the templates and click ```next```.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/empty-project.png">
</p>

&nbsp;
&nbsp;

## Step 3

Configure your project settings:

* In the ```Project Name``` box provide a name for the project (e.g: HelloWorld)
* In the ```Location``` box browse to the location where you want to save your project (e.g. the exercises folder of your CodeLab GitHub repository).

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/configure-project.png">
</p>

&nbsp;
&nbsp;

## Step 4

You will be presented with the following screen (Solution Explorer may appear on the left or the right).

* In the solution explorer right click the ```Source Files``` folder
* Click ```Add → New Item``` from the popup menu that appears

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/add-new.png">
</p>

&nbsp;
&nbsp;

## Step 5

Add a new C++ (```.cpp```) file and name it ```main.cpp```. Click ```Add```.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/main.png">
</p>

&nbsp;
&nbsp;

## Step 6

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

## Additional Note

You might find that the console window shuts immediately when reaching the end of your program. If so simply add the following line at the end of your program:

```C++
system("pause");
```

This line of code will wait for you to press enter before closing the console window. This line of code should only be used while testing and should be removed from final versions of your projects.

