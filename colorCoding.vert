#version 120

attribute vec2 vertexPosition;
attribute vec4 vertexColor;

varying vec4 fragColor;


void main(){
    gl_Position.xy = vertexPosition;
    gl_Position.z=0.0;
    gl_Position.w=1.0;
    
    fragColor = vertexColor;

}
