#version 120

varying vec4 fragColor;
vec4 color;

uniform float time;

void main(){
    color = fragColor;
    gl_FragColor = color + vec4 (sin(time+1)*0.5,
                                 cos(time+2)*0.5,
                                 (sin(time)+1.0)*0.5,
                                 0.0);
}
