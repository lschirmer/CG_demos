#version 330 core
layout(location = 0) out vec3 color;

in vec3 Position_worldspace;
in vec3 Normal_cameraspace;
in vec3 EyeDirection_cameraspace;
in vec3 LightDirection_cameraspace;
in vec4 ShadowCoord;
uniform sampler2D myTextureSampler;
uniform mat4 MV;
uniform vec3 LightPosition_worldspace;
uniform sampler2DShadow shadowMap;

float xPixelOffset = 1 / (1024*2);
float yPixelOffset  = 1 / (768*2);

float random(vec3 seed, int i){
	vec4 seed4 = vec4(seed,i);
	float dot_product = dot(seed4, vec4(12.9898,78.233,45.164,94.673));
	return fract(sin(dot_product) * 43758.5453);
}

float lookup( vec2 offSet)
{
	return  textureProj(shadowMap, ShadowCoord + vec4(offSet.x * xPixelOffset * ShadowCoord.w, offSet.y * yPixelOffset * ShadowCoord.w, 0.05, 0.0));
}

void main(){
	vec3 LightColor = vec3(1,1,1);
	float LightPower = 1.0f;
	vec3 MaterialDiffuseColor = vec3(0,1,1);
	vec3 MaterialAmbientColor = vec3(0.1,0.1,0.1) * MaterialDiffuseColor;
	vec3 MaterialSpecularColor = vec3(0.3,0.3,0.3);
	vec3 n = normalize( Normal_cameraspace );
	vec3 l = normalize( LightDirection_cameraspace );
	float cosTheta = clamp( dot( n,l ), 0,1 );
	vec3 E = normalize(EyeDirection_cameraspace);
	vec3 R = reflect(-l,n);
	float cosAlpha = clamp( dot( E,R ), 0,1 );
	float visibility=1.0;
	//usado para evitar shadow acne
    float bias = 0.005;
	
    for (int i=0;i<4;i++){
		int index = i;
		visibility -= 0.2*(1.0-texture( shadowMap, vec3(ShadowCoord.xy , (ShadowCoord.z-bias)/ShadowCoord.w) ));
	}
	//PCF
	float shadow = visibility;
	if(visibility <= 0.8 ){
		shadow = 1;
		float x,y;
					for (y = -2.5 ; y <=2.5 ; y+=1.0)
						for (x = -2.5 ; x <=2.5 ; x+=1.0)
							shadow += lookup(vec2(x,y));
					
					shadow /= 25.0 ;
	}
	color = MaterialAmbientColor + (shadow+0.2) * MaterialDiffuseColor * LightColor * LightPower * cosTheta+ (shadow+0.2) * MaterialSpecularColor * LightColor * LightPower * pow(cosAlpha,5);
		
}