# ofxProjectorBlend
(version 2.0)


This addon is used to take a normal openFrameworks project and split it into 2 or more pieces that can be projected using 2 or more projectors. This usually involves something like a [Matrox DualHead](http://www.matrox.com/graphics/en/products/gxm/dh2go/digital_se/) or a graphics card with multiple outputs. For the best results, the projectors should also have a hardware blending feature so that the overlapped portions are not brighter than the non-overlapped sections.


--------
	Permission is hereby granted, free of charge, to any person
	obtaining a copy of this software and associated documentation
	files (the "Software"), to deal in the Software without
	restriction, including without limitation the rights to use,
	copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following
	conditions:
	
	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.
----------


### Credits
- Based on Paul Bourke's paper, ["Edge blending using commodity projectors"](http://paulbourke.net/texture_colour/edgeblend/)
- Quartz Shader implemenation by Matthias Oostrik ( http://www.oostrik.net )
- Original openFrameworks addon adaptation by [James George](http://www.jamesgeorge.org)
- in collaboration with [FlightPhase](http://www.flightphase.com) 
- additions by [Marek Bereza](http://www.mazbox.com/)
- This fork was created by [Jeff Crouse](http://www.jeffcrouse.info) specifically for the [Interactive openFrameworks workshop at Kitchen Table Coders](http://kitchentablecoders.com/2012/10/20/intermediate-of-a/).  It is simplified in a few minor ways.

### Used in

- Flightphase's [Infiniti MOI project](http://vimeo.com/14588336)
- Hellicar and Lewis [Coke24 project](http://www.hellicarandlewis.com/2011/03/22/coke-24hr-music/)
- Flightphase's [University of Dayton interactive wall](http://www.flightphase.com/main_wp/expanded-media/interactive-wall-at-ud)
- Flightphase's ["Paik Times Five"](http://www.flightphase.com/main_wp/expanded-media/paik-times-five)


### Examples

#### Two Screens

This app shows the simplest usage of the addon: a typical 2-screen horizontal layout.  

![Two Screens](http://4u.jeffcrouse.info/of/pblend/two_screens.png)

#### Three Vertical 

![Three Vertical](http://4u.jeffcrouse.info/of/pblend/three_vertical.png)

#### Simple Gui

For this example, get to additional addons: [ofxMSAInteractiveObject](https://github.com/memo/ofxMSAInteractiveObject) [[direct download link](https://github.com/memo/ofxSimpleGuiToo/archive/master.zip)] and [ofxSimpleGuiToo](https://github.com/memo/ofxSimpleGuiToo) [[direct download link](https://github.com/memo/ofxMSAInteractiveObject/archive/master.zip)].  

![Gui Controls](http://4u.jeffcrouse.info/of/pblend/gui_controls.png)

#### Blend Clown

This example shows a stupid little technique that has come in very handy for me when aligning multiple projectors.  The uniform grid isn't ideal for alignment because you might be overlapping too many grid squares.  With the clown, you can be sure that you are aligning properly.

![The Blend Clown](http://4u.jeffcrouse.info/of/pblend/blend_clown.png)