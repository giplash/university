export const fetchData = async () => {
  try {
    const res = await fetch('/api/products');
    const resJSON = await res.json();
    if (resJSON.success === false) {
      alert(resJSON.errorMessage);
      return;
    }
    const array = resJSON.products;
    return array.reduce((acc, item) => {
      acc[item.id] = item;
      return acc;
    }, {});
  } catch (e) {
    return Promise.reject();
  }
};

export const buyProduct = async (id, quantity, cardData) => {
  try {
    const res = await fetch('/api/products/buy', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({
        id,
        quantity,
        cardData
      })
    });
    const resJSON = await res.json();
    if (resJSON.success === false) {
      alert(resJSON.errorMessage);
      return Promise.reject();
    }
    return Promise.resolve();
  } catch(e) {
    return Promise.reject();
  }
};

export const addProduct = async info => {
  try {
    const res = await fetch('/api/products/add', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({ ...info })
    });
    const resJSON = await res.json();
    if (resJSON.success === false) {
      alert(resJSON.errorMessage);
      return;
    }
    return Promise.resolve();
  } catch(e) {
    return Promise.reject();
  }
};