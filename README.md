# OpenGL Helper

This project provides some useful functionalities for OpenGL development (see feature section below).

## Installing

We recommend using this sources from the Git repository. This way you can easily get updates by issuing a `git pull` inside the respective directory.

Note that you should not make any changes to the file inside the directory. If you need changes to be made, please open an issue on the project page. You can also make your changes in a forked repository and submit a merge request so we can review and merge your changes into the main project.

Go into the folder that contains your project sources and run the following command.

If your project already uses Git:
`git submodule add git@github.com:saitho/opengl-helper.git OpenGLHelper`
If your project does not use Git:
`git clone git@github.com:saitho/opengl-helper.git OpenGLHelper`

This will create a new folder OpenGLHelper which contains the CPP and Header-Files. Then add the files to your project (if needed) and use the Header-Files as you would with your own code.

## Using

Include the header file by:

```
#include “OpenGLHelper/ColorHelper.h“
```

### Setting up XCode

Go into your XCode project and create a new Group. Inside that group include all the files from the ./OpenGLHelper directory. Otherwise XCode won’t compile the sources.

## Features

### ColorHelper

The ColorHelper extends the OpenGL color functions and allows passing in predefined colors by name, RGB values and hexadecimal values.

```
// color from hex value (e.g. #bbb, #ababab)
glColor3f( ColorHelper::getColor(“#ccc“) );
// color from presets
glColor3f( Color::RED );
// color from RGB values
glColor3f( RGBColor(128, 128, 128) );
```

### Showing x, y and z axes

```
#include "../OpenGLHelper/AxisHelper.h"
// in display func:
AxisHelper ah = AxisHelper();
ah.renderAxes();
```

Available settings:

setLength(float lineLength)
setWidth(float lineWidth)
setShowOrigin(bool showOrigin)

### OpenGL objects

OpenGL objects enable you to manipulate the object by calling transformation and translation methods on the object. See examples/ directory for example code.
