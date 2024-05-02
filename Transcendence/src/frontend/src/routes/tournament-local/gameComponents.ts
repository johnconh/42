import * as THREE from "three"


//======================================
//			CAMARA
//======================================

const windowWidth = 800;
const windowHeight = 500;

console.log(windowWidth / windowHeight)
export const camera = new THREE.PerspectiveCamera(100, windowWidth / windowHeight, 0.1, 1000);
camera.position.set(0, 75, 60);
camera.lookAt(new THREE.Vector3(0, 1, 0));

//======================================
//			LIGHT
//======================================

// Crear la luz direccional
export const directionalLight = new THREE.DirectionalLight(0xffffff, 1); // Color blanco, intensidad 1
directionalLight.position.set(10, 8, -10);
directionalLight.intensity = 0.8;  // Cambiar la intensidad a 0.5

// Configurar la dirección de la luz para que apunte hacia abajo
directionalLight.target.position.set(0, 0, 0); // Establecer un objetivo para la luz
directionalLight.target.updateMatrixWorld(); // Actualizar la matriz del mundo del objetivo


// Crear la luz direccional
export const directionalLight2 = new THREE.DirectionalLight(0xffffff, 1); // Color blanco, intensidad 1
directionalLight2.position.set(-10, 8, 10);
directionalLight2.intensity = 0.8;  // Cambiar la intensidad a 0.5

// Configurar la dirección de la luz para que apunte hacia abajo
directionalLight2.target.position.set(0, 0, 0); // Establecer un objetivo para la luz
directionalLight2.target.updateMatrixWorld(); // Actualizar la matriz del mundo del objetivo


//======================================
//			SPACE
//======================================

// Generate a plane
const planeGeometry = new THREE.PlaneGeometry(120, 80);
const planeMaterial = new THREE.MeshToonMaterial();
export const planeMesh = new THREE.Mesh(planeGeometry, planeMaterial);
planeMesh.position.set(0, 0, 0);
planeMesh.rotation.x = -0.5 * Math.PI; // This rotates the plane to match the grid.



//======================================
//			PLAYERS
//======================================

// Generate de box
const geometry = new THREE.BoxGeometry(8, 8, 24);
const material = new THREE.MeshToonMaterial({ color: 0x0563FF });
export const cube = new THREE.Mesh(geometry, material);
cube.position.set(-56, 4, 0)


const edges = new THREE.EdgesGeometry(geometry);
const lineMaterial = new THREE.LineBasicMaterial({ color: 0x000000 }); // Color de los bordes
const wireframe = new THREE.LineSegments(edges, lineMaterial);


// Crear geometría de bordes
cube.add(wireframe); // Añadir los bordes al cubo

// Generate de box
export const cube2 = new THREE.Mesh(geometry, material);
cube2.position.set(56, 4, 0)

// Crear geometría de bordes
const wireframe2 = new THREE.LineSegments(edges, lineMaterial);
cube2.add(wireframe2); // Añadir los bordes al cubo


//======================================
//			BALL
//======================================

const radio = 3; // Radio de la esfera
const segmentos = 32; // Número de segmentos que forman la esfera
const geometry3 = new THREE.SphereGeometry(radio, segmentos, segmentos);
const material3 = new THREE.MeshToonMaterial({ color: 0xFF0000 }); // Color rojo en hexadecimal
export const esfera = new THREE.Mesh(geometry3, material3);
esfera.position.set(0, 4, 0); // Establecer la posición de la esfera en la escena


//======================================
//			WALLS
//======================================


// Generate de top wall
const wallGeometry = new THREE.BoxGeometry(120, 8, 8);
const wallMaterial = new THREE.MeshPhongMaterial({ color: 0xBFFF00, transparent: true, opacity: 0.8 });

// Crear geometría de bordes
const wallEdges = new THREE.EdgesGeometry(wallGeometry);
const lineWallMaterial = new THREE.LineBasicMaterial({ color: 0x000000 }); // Color de los bordes

// Create topWall
export const topWall= new THREE.Mesh(wallGeometry, wallMaterial);
topWall.position.set(0, 4, 44)
const topWallWireframe = new THREE.LineSegments(wallEdges, lineWallMaterial);
topWall.add(topWallWireframe); // Añadir los bordes al cubo


// Create topWall
export const bottomWall= new THREE.Mesh(wallGeometry, wallMaterial);
bottomWall.position.set(0, 4, -44)
const bottomWallWireframe = new THREE.LineSegments(wallEdges, lineWallMaterial);
bottomWall.add(bottomWallWireframe); // Añadir los bordes al cubo


//======================================
//			SCENE
//======================================

export const scene = new THREE.Scene();

// Add elements to the scene
scene.add(directionalLight);
scene.add(directionalLight2);
scene.add(planeMesh);
scene.add(cube);
scene.add(cube2);
scene.add(esfera);
scene.add(topWall);
scene.add(bottomWall);

//======================================
//			MANAGE GAME
//======================================

export function updateGame(response, renderer)
{
	esfera.position.z = response.objects.ball_y;
	esfera.position.x = response.objects.ball_x;
	cube.position.z = response.objects.p1_y;
	cube2.position.z = response.objects.p2_y;
}
