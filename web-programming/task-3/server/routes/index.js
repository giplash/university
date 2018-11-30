import productsRouter from './products';

export default app => {
  app.use('/api/products', productsRouter);
  app.get('*', (req, res) => {
    res.render('index');
  });
};