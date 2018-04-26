/* Basic ReViz3d project
check http://lucascassiano.github.io/reViz3d/ for documentation
*/

var cube;
var t = 0;
//This method will be called when the Component is Mounted
Setup = (scene, camera, renderer) => {
    cube = new Cube();
    scene.add(cube);

    //config model
    //scene.add(MODELS.obj.sensor);
    MODELS.obj.sensor.scale.set(0.5, 0.5, 0.5);
    MODELS.obj.sensor.rotation.x = Math.PI * 0.5;
}

//Thi method will be called 30 times per second (30FPS)
Update = (scene, camera, renderer) => {
    //cube.position.y = 5 * Math.sin(t);
    //t += 1.0 / 30;
    cube.position.y = parseInt(MQTT);
    cube.position.y = 20;
    var scale = SERIAL / 50;
    cube.scale.set(1, 1, 1);
    //console.log(String(MQTT));

    cube.position.y = SERIAL / 100;
}