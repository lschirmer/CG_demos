#version 330 core

layout (location = 0) out vec4 fColor;

uniform sampler2D diffuseMap;
uniform sampler2D normalMap;
uniform sampler2D vertexMap;

uniform mat4 viewMatrix;

const int numLights = 50;
in vec2 vTexCoord;

layout (std140) uniform LightSource
{
  vec4 lightPos[numLights];
};


void main()
{
 
  vec3 normal = vec3(texture(normalMap, vTexCoord));
  fColor = vec4(0.f);
  vec4 cordifusa = texture(diffuseMap,vTexCoord);
  vec3 verts = vec3(texture(vertexMap,vTexCoord));

  for(int i = 0; i< 50; i++){
    
	vec3 luz = (viewMatrix * lightPos[i]).xyz;
	vec3 luz_dir = luz - verts;
	float dist = length(luz_dir);

	float diff = max(dot(normal,normalize(luz_dir)),0.0);
	fColor += (diff * cordifusa.rgb) / (dist);
	vec3 reflection = normalize(reflect(-normalize(luz_dir),normal));
	float spec = max(dot(reflection,normalize(-verts)),0.0);

	if(diff!=0){
		float fspec = pow(spec,64.f);
		vec3 specColor = (vec3(fspec));
		fColor.rgb += specColor;
	}
  }
 }