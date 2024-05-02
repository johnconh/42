export async function gameOne() {
    gameOn = true;
    const windowWidth = 800;
    const windowHeight = 500;

    await delay(1000);
    renderer = new THREE.WebGLRenderer();
    renderer.setSize(windowWidth, windowHeight);
    document.getElementById('canvas-container').appendChild(renderer.domElement);
    renderer.render(scene, camera);

    const socket = new WebSocket(
        "ws://" +
        "localhost:61001" + // cambiar si aplica para porduccion */
        "/ws/game/" +
        gameID +
        "&" + // cambiar con uuid para cada partida */
        data.mainUserData.user_name +
        "/" // cambiar con uuid para cada partida */
    );

    socket.addEventListener("message", function (event) {
        const response = JSON.parse(event.data);
        console.log(socket);
        console.log(response);
        if (response.type == "playerNames") {
            console.log("response: ", response);
            player_1 = response.player1;
            player_2 = response.player2;
        } else if (response.type == "stateUpdate") {
            /* console.log(response); */
            console.log("response: ", response);
            esfera.position.z = response.objects.ball_y;
            esfera.position.x = response.objects.ball_x;
            cube.position.z = response.objects.p1_y;
            cube2.position.z = response.objects.p2_y;
            renderer.render(scene, camera);
            score_1 = response.objects.score_1;
            score_2 = response.objects.score_2;
            player_1 = response.objects.player1;
            player_2 = response.objects.player2;
        } else if (response.type == "playerId") {
            playerId = response.playerId;
        } else if ((response.type = "finish_game")) {
            socket.close();
            game_ended = true;
            console.log("PIDEEEEEEEE");
            saveGame(
                "testroom2",
                player_1,
                player_2,
                score_1,
                score_2,
                "tournament"
            );
            modal.showModal();
        }
    });

    window.addEventListener("keydown", function (event) {
        if (event.key === "ArrowDown") {
            // key code for the arrow down key
            const message = {
                playerId: playerId,
                type: "up",
            };
            socket.send(JSON.stringify(message));
            console.log("up");
        } else if (event.key === "ArrowUp") {
            // key code for the arrow down key
            const message = {
                playerId: playerId,
                type: "down",
            };
            socket.send(JSON.stringify(message));
        } else if (event.key === 32) {
            // key code for the space
            const message = {
                playerId: sessionStorage.getItem("playerId"),
                type: "puase",
            };
            socket.send(JSON.stringify(message));
        }
    });
}

export async function finalGame() {
    gameOn = true;
    const windowWidth = 800;
    const windowHeight = 500;

    await delay(1000);
    renderer = new THREE.WebGLRenderer();
    renderer.setSize(windowWidth, windowHeight);
    document.getElementById('canvas-container').appendChild(renderer.domElement);
    renderer.render(scene, camera);

    const socket = new WebSocket(
        "ws://" +
        "localhost:61001" + // cambiar si aplica para porduccion */
        "/ws/game/" +
        gameID +
        "&" + // cambiar con uuid para cada partida */
        data.mainUserData.user_name +
        "/" // cambiar con uuid para cada partida */
    );

    socket.addEventListener("message", function (event) {
        const response = JSON.parse(event.data);
        console.log(socket);
        console.log(response);
        if (response.type == "playerNames") {
            console.log("response: ", response);
            player_1 = response.player1;
            player_2 = response.player2;
        } else if (response.type == "stateUpdate") {
            /* console.log(response); */
            console.log("response: ", response);
            esfera.position.z = response.objects.ball_y;
            esfera.position.x = response.objects.ball_x;
            cube.position.z = response.objects.p1_y;
            cube2.position.z = response.objects.p2_y;
            renderer.render(scene, camera);
            score_1 = response.objects.score_1;
            score_2 = response.objects.score_2;
            player_1 = response.objects.player1;
            player_2 = response.objects.player2;
        } else if (response.type == "playerId") {
            playerId = response.playerId;
        } else if ((response.type = "finish_game")) {
            socket.close();
            game_ended = true;
            console.log("PIDEEEEEEEE");
            saveGame(
                "testroom2",
                player_1,
                player_2,
                score_1,
                score_2,
                "tournament"
            );
            modal.showModal();
        }
    });

    window.addEventListener("keydown", function (event) {
        if (event.key === "ArrowDown") {
            // key code for the arrow down key
            const message = {
                playerId: playerId,
                type: "up",
            };
            socket.send(JSON.stringify(message));
            console.log("up");
        } else if (event.key === "ArrowUp") {
            // key code for the arrow down key
            const message = {
                playerId: playerId,
                type: "down",
            };
            socket.send(JSON.stringify(message));
        } else if (event.key === 32) {
            // key code for the space
            const message = {
                playerId: sessionStorage.getItem("playerId"),
                type: "puase",
            };
            socket.send(JSON.stringify(message));
        }
    });
}