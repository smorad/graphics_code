#version 120

// both cpu and gpu can access a uniform variable
uniform sampler2D diffuse;

varying vec2 textCoord0;

void main(){
	gl_FragColor = texture2D(diffuse, textCoord0);
}