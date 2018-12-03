一. 光照基础
1. 环境光
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
	
2. 漫反射
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;
	
3. 镜面反射
	float specularStrength = 0.5;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * lightColor;
	
	
4.顶点或片元的颜色值
vec3 result = (ambient + diffuse + specular) * objectColor;
FragColor = vec4(result, 1.0);

二. Phong和Blinn-Phong光照模型区别
1. Phone模型计算中的一个关键步骤就是反射向量R的计算：
2. Phong模型中计算反射光线的向量是一件相对比较耗时的任务，
因此Blinn-Phong对这一点进行了改进: 光入射方向L和视点方向V的中间向量替换R。

三. shader 的例子实现
1. 顶点shader的基本实现
2. 三种不同实现的对比




