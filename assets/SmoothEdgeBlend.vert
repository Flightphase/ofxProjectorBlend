/**
 * Sept 20 2010
 * 
 * This shader is ripped out of a Quartz Composer patch by  Matthias Oostrik
 * from http://local.wasp.uwa.edu.au/~pbourke/texture_colour/edgeblend/
 * Original Core Image filter converted by James George ( http://www.jamesgeorge.org/ )
 * for ofxProjectorBlend addon for openFrameworks ( http://www.openframeworks.cc )
 *
 * Originally used in the Infiniti MOI project for projector blending ( http://vimeo.com/14588336 )
 *
 * This shader is capable of blending on all sides, but ofxProjectorBlend currently
 * just uses the shader for two projections at once.
 */
 
void main(void)
{
	gl_Position = ftransform();
	gl_TexCoord[0] = gl_MultiTexCoord0;
}
