#version 120

varying vec2 fragPosition;
varying vec4 fragColor;
varying vec2 fragUV;
vec4 color;

uniform float time;
uniform sampler2D mySampler;

void main(){
    
    vec4 textureColor = texture2D (mySampler, fragUV);
    
    color = textureColor * fragColor;
    gl_FragColor = color + vec4 (sin(time+1)*0.5,
                                 cos(time+2)*0.5,
                                 (sin(time)+1.0)*0.5,
                                 0.0);
}
