function saveStatus(item, username) {
  if (item.player1 === username && item.player1_result > item.player2_result) {
    item.game_status = true // El username ganó como player1
  } else if (item.player2 === username && item.player2_result > item.player1_result) {
    item.game_status = true // El username ganó como player2
  } else {
    item.game_status = false // El username no ganó
  }
}

function formatDate(item) {
  const date = new Date(item.date)
  const options = { year: 'numeric', month: 'short', day: 'numeric' }
  item.game_date = date.toLocaleDateString('en-US', options)
}

async function getRivalPhoto(item, username) {
  let rivalUsername = username !== item.player1 ? item.player1 : item.player2

  const response = await fetch('http://backend:61001/accounts/username/', {
    method: 'POST',
    headers: {
      Accept: 'application/json',
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({
      user_name: rivalUsername,
    }),
  })

  const json = await response.json()
  item.rival_username = rivalUsername
  //   item.rival_photo = 'https://0.0.0.0:443/media/' + json.avatar_fileName
  item.rival_photo = 'https://localhost/media/' + json.avatar_fileName
  item.rival_email = json.email
  /* console.log(item); */
}

export async function getWinners(data, username) {
  const promises = data.map(async item => {
    saveStatus(item, username)
    formatDate(item)
    await getRivalPhoto(item, username)
    return item
  })

  return Promise.all(promises)
}
