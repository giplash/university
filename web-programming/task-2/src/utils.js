export const generateQuantity = () => Math.round(Math.random() * 200);
export const generateId = data => {
  let id = 0;
  do {
    id++;
  } while(data[id]);
  return id;
};
