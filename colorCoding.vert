#version 120

attribute vec2 vertexPosition;
attribute vec4 vertexColor;
attribute vec2 vertexUV;

varying vec2 fragPosition;
varying vec4 fragColor;
varying vec2 fragUV;


void main(){
    gl_Position.xy = vertexPosition;
    gl_Position.z=0.0;
    gl_Position.w=1.0;
    
    fragPosition = vertexPosition;
    fragColor = vertexColor;
    fragUV = vec2(vertexUV.x,1.0-vertexUV.y);

}
