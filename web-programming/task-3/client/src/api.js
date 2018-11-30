export const fetchData = async () => {
  try {
    const res = await fetch('/api/products');
    const array = await res.json();
    return array.reduce((acc, item) => {
      acc[item.id] = item;
      return acc;
    }, {});
  } catch (e) {
    console.log(e);
  }
}