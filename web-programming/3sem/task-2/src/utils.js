export const generateQuantity = () => Math.round(Math.random() * 200);

export const generateId = data => {
  let id = 0;
  do {
    id++;
  } while(data[id]);
  return id;
};

export const validate = (name, price, quantity) => {
  const res = [null, null, null];
  if (name === '' || !isNaN(+name)) {
    res[0] = 'Invalid name';
  }
  if (isNaN(price) || price <= 0) {
    res[1] = 'Invalid price';
  }
  if (isNaN(quantity) || quantity <= 0) {
    res[2] = 'Invalid quantity';
  }
  return res;
};

export const sort = (data, type) => {
  const array = Object.values(data);
  if (type === 'name') {
    return array.sort((a, b) => a.name.localeCompare(b.name));
  }
  if (type === 'id') {
    return array.sort((a, b) => a.id - b.id);
  }
  if (type === 'price') {
    return array.sort((a, b) => a.price - b.price);
  }
  if (type === 'quantity') {
    return array.sort((a, b) => a.quantity - b.quantity);
  }
};

