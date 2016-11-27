#version 120

vec3 color;

void main(){
    color = vec3(1.0,0.0,0.0);
    gl_FragColor = vec4(color,1.0);
}
